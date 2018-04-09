#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(){
}

Player::Player(int playerIndex,Strategy* strategy)
{	
	this->phaseObserver = new PhaseObserver(this,0);
	this->basicGameStatisticsObserver = new BasicGameStatisticsObserver(this);
	this->playerDominationObserverDecorator = new PlayerDominationObserverDecorator(this);
	this->playerHandsObserverDecorator = new PlayerHandsObserverDecorator(this);
	this->victoryCoinsObserverDecorator = new VictoryCoinsObserverDecorator(this);
	this->needDecorator = 'N';
	this->strategy = strategy;
	this->Coins_Inhand = 5;
	this->playerIndex = playerIndex;
	this->specialPowerToken = 0;
	this->Tokens_Unused = 0;
	this->Tokens_Inhand = 0;
	this->Coins_Unused = 0;
	this->Dice_Number_Unused = 0;
	this->Dice_Number_Inhand = 0;
	this->needPlayerDominationObserver = false;
	this->needPlayerHandsObserver = false;
	this->needVictoryCoinsObserver = false;
}

Player::~Player()
{
}

void Player::display()
{

	cout << "The Regions_Unused is : ";
	for (int i = 0; i < Regions_Unused.size(); i++)
	{
		cout << (char)(Regions_Unused[i].getNodeNumber()+64)<<" ";
	}
	cout<< endl;
	cout << "The Regions_Inhand is : ";
	for (int i = 0; i < Regions_Inhand.size(); i++)
	{
		cout << (char)(Regions_Inhand[i].getNodeNumber() + 64)<<" ";
	}
	cout << endl; 
	cout << "The Tokens_Unused is : " << Tokens_Unused << endl;
	cout << "The Tokens_Inhand is : " << Tokens_Inhand << endl;
	cout << "The Race_Unused is : " << this->getRace_Unused().GetRaceName() << endl;
	cout << "The Race_Inhand is : " << this->getRace_Inhand().GetRaceName() << endl;
	cout << "The Badges_Unused is : " << this->getBadges_Unused().GetBadgeName() << endl;
	cout << "The Badges_Inhand is : " << this->getBadges_Inhand().GetBadgeName()<< endl;
	cout << "The Coins_Unused is : " << Coins_Unused << endl;
	cout << "The Coins_Inhand is : " << Coins_Inhand << endl;

}

void Player::setPlayerIndex(int i)
{
	playerIndex = i;
}
int Player::getPlayerIndex()
{
	return playerIndex;
}
vector<Region> Player::getRegions_Unused()
{
	return Regions_Unused;
}

vector<Region> Player::getRegions_Inhand()
{
	return Regions_Inhand;
}

void Player::setRegions_Unused(vector<Region> regionList)
{
	this->Regions_Unused = regionList;
}

void Player::setRegions_Inhand(Region& region)
{
	this->Regions_Inhand.push_back(region);
}

void Player::setRegions_Inhand(vector<Region> regionList)
{
	Regions_Inhand = regionList;
}

void Player::setSpecialPowerToken(int i)
{
	specialPowerToken = i;
}

int Player::getSpecialPowerToken()
{
	return specialPowerToken;
}
void Player::setDice_Number_Unused(int i)
{
	Dice_Number_Unused = i;
}
int Player::getDice_Number_Unused()
{
	return Dice_Number_Unused;
}
void Player::setDice_Number_Inhand(int i)
{
	Dice_Number_Inhand = i;
}

int Player::getDice_Number_Inhand()
{
	return Dice_Number_Inhand;
}

bool Player::notAdjacentRegion(int regionIndex)
{
	for (int i = 0; i < getRegions_Inhand().size(); i++) {

		for (int j = 0; j < getRegions_Inhand()[i].getAdjacentNodes().size(); j++) {

			if (regionIndex == getRegions_Inhand()[i].getAdjacentNodes()[j]) {
				return false;
			}
		}
	}

	for (int i = 0; i < getRegions_Unused().size(); i++) {

		for (int j = 0; j < getRegions_Unused()[i].getAdjacentNodes().size(); j++) {

			if (regionIndex == getRegions_Unused()[i].getAdjacentNodes()[j]) {
				return false;
			}
		}
	}
	cout << "The region you chose is not adjacent to regions you hold,please choose again:" << endl;
	return true;
}

bool Player::notOnTheEdges(char regionNumber,Map map)
{
	for (int i = 0; i < map.getEdgeRegions().size(); i++)
	{
		if (regionNumber == map.getEdgeRegions()[i]) {
			return false;
		}
	}
	cout << "Please choose from above edge list" << endl;
	return true;
}

bool Player::belongItself(int regionIndex)
{
	for (int i = 0; i < getRegions_Inhand().size(); i++) {
		if (Regions_Inhand[i].getNodeNumber() == regionIndex) {
			cout << "--------------This region is already belongs to you, please choose again : -------------" << endl;
			return true;
		}
	}
	for (int i = 0; i < getRegions_Unused().size(); i++)
	{
		if (Regions_Unused[i].getNodeNumber() == regionIndex) {
			cout << "--------------This region is already belongs to you, please choose again : -------------" << endl;
			return true;
		}
	}
	return false;
}

bool Player::isWaterRegion(int regionIndex, Map& map)
{
	if (map.regionList[regionIndex - 1].getRegionTpye()._Equal("water")) {
		cout << "The region you choose cannot be conquered" << endl;
		return true;
	}
	return false;
}

bool Player::notValidInput(int regionIndex, Map map)
{
	if (regionIndex < 1||regionIndex >=map.getRegionList().size()) {
		cout << "Input value out of map region range,please enter again" << endl;
		return true;
	}
	return false;
}

void Player::conquereOthers(int regionIndex, Map& map, vector<Player>& playerList)
{
	int returnBackToken = map.getRegion(regionIndex).getCurrentOcupiedToken() - 1;//consume 1 token if someone conquered region belonging to others.

																				  /*get current player's information*/
	int currentPlayer = map.regionList[regionIndex - 1].getplayerNumber();
	string currentRace = map.regionList[regionIndex - 1].getOcupiedRace();
	if (currentRace.compare(playerList[currentPlayer - 1].getRace_Inhand().GetRaceName()) == 0)
	{
		playerList[currentPlayer - 1].setTokens_Inhand(returnBackToken + playerList[currentPlayer - 1].getTokens_Inhand());//return tokens to other players. 
		for (int i = 0; i < playerList[currentPlayer - 1].Regions_Inhand.size(); i++)
		{
			if (playerList[currentPlayer - 1].Regions_Inhand[i].getNodeNumber() == regionIndex) {//delete this region from previous holder's hand
				playerList[currentPlayer - 1].Regions_Inhand.erase(playerList[currentPlayer - 1].Regions_Inhand.begin() + i);
				if (getNeedPlayerDominationObserver()) {
					playerDominationObserverDecorator->currentPlayerIndex = this->getPlayerIndex();
					playerDominationObserverDecorator->oponentPlayerIndex = currentPlayer;
					playerDominationObserverDecorator->setMethod(2);
					notify("PlayerDominationObserverDecorator", regionIndex);
					map.notify();
				}
				return;
			}
		}
	}
	else {
		for (int i = 0; i < playerList[currentPlayer - 1].Regions_Unused.size(); i++)
		{
			if (playerList[currentPlayer - 1].Regions_Unused[i].getNodeNumber() == regionIndex) {//delete this region from previous holder's hand
				playerList[currentPlayer - 1].Regions_Unused.erase(playerList[currentPlayer - 1].Regions_Unused.begin() + i);
				if (getNeedPlayerDominationObserver()) {
					playerDominationObserverDecorator->currentPlayerIndex = this->getPlayerIndex();
					playerDominationObserverDecorator->oponentPlayerIndex = currentPlayer;
					playerDominationObserverDecorator->setMethod(2);
					notify("PlayerDominationObserverDecorator", regionIndex);
					map.notify();
				}
				return;
			}
		}
		/*after all of decaded race ocupied regions has been conquered,this combo should be putted back to the box*/
		playerList[currentPlayer - 1].setRace_Unused(NULL);
		playerList[currentPlayer - 1].setBadges_Unused(NULL);
		playerList[currentPlayer - 1].setUnusedRaceName("");
	}
}

void Player::executeStrategy(vector<Player>& playerList, Map & map, int currentPlayer, int roundNumber, Race race[], Badges badges[])
{
	this->strategy->execute(playerList,map, currentPlayer,roundNumber,race,badges);
}

char Player::getNeedDecorator()
{
	return needDecorator;
}

void Player::setNeedDecorator(char needDecorator)
{
	this->needDecorator = needDecorator;
}

bool Player::getNeedPlayerDominationObserver()
{
	return needPlayerDominationObserver;
}

bool Player::getNeedPlayerHandsObserver()
{
	return needPlayerHandsObserver;
}

bool Player::getNeedVictoryCoinsObserver()
{
	return needVictoryCoinsObserver;
}

void Player::setNeedPlayerDominationObserver(bool choice)
{
	this->needPlayerDominationObserver = choice;
}

void Player::setNeedPlayerHandsObserver(bool choice)
{
	this->needPlayerHandsObserver = choice;
}

void Player::setNeedVictoryCoinsObserver(bool choice)
{
	this->needVictoryCoinsObserver = choice;
}

void Player::notify(string x,int y)
{
	if (x == "PhaseObserver") {
			_observers[0]->update(y);
			return;
	}else if (x == "BasicGameStatisticsObserver") {
		_observers[1]->update(y);
		return;
	}
	if(_observers.size() >=3){//case for decorated 
		if (x == "PlayerDominationObserverDecorator") {
			_observers[2]->update(y);
			return;
		}
		else if (x == "PlayerHandsObserverDecorator") {
			_observers[3]->update(y);
			return;
		}
		else if (x == "VictoryCoinsObserverDecorator") {
			_observers[4]->update(y);
			return;
		}
	}
}

void Player::redistribution(Map& map)
{
	int getTokenFromHand = this->getTokens_Inhand();
	int getTokenFromMap = 0;
	for (int i = 0; i < getRegions_Inhand().size(); i++)
	{
		getTokenFromMap += getRegions_Inhand()[i].getCurrentOcupiedToken() - 1;
	}
	cout << "Now you can reset tokens on the regions you have got.  " << endl;
	int tokenCanUsedToReSet = getTokenFromHand +getTokenFromMap;
	this->setTokens_Inhand(tokenCanUsedToReSet);




	for (int i = 0; i < this->getRegions_Inhand().size(); i++)
	{
		int currentRegion = this->getRegions_Inhand()[i].getNodeNumber();
		this->Regions_Inhand[i].setCurrentOcupiedToken(1);
		map.regionList[currentRegion - 1].setCurrentOcupiedToken(1);
	}
	int numberToSetToken = 0;

	while (this->getTokens_Inhand() > 0)
	{
		for (int i = 0; i < this->getRegions_Inhand().size(); i++)
		{
			cout << "Now you have " << this->getTokens_Inhand() << " tokens you can use . " << endl;
			cout << "For region :" << (char)(getRegions_Inhand()[i].getNodeNumber() + 64) << endl;
			cout << "Enter the token number you want to  put on it : " << endl;		
			cin >> numberToSetToken;
			int currentRegion = this->getRegions_Inhand()[i].getNodeNumber();

			while (numberToSetToken<0 || numberToSetToken > this->getTokens_Inhand())
			{			
				cout << "Please enter a number between 0 and " << this->getTokens_Inhand() << endl;
				cin >> numberToSetToken;
			}
			this->Regions_Inhand[i].setCurrentOcupiedToken(numberToSetToken+1);
			map.regionList[currentRegion - 1].setCurrentOcupiedToken(numberToSetToken + 1);
			this->setTokens_Inhand(this->getTokens_Inhand() - numberToSetToken);
			if (this->getTokens_Inhand() == 0)
				return;

		}
	}
}

string Player::getUnusedRaceName()
{
	return unusedRaceName;
}

void Player::setUnusedRaceName(string s)
{
	unusedRaceName = s;
}

void Player::setTokens_Inhand(int i)
{
	Tokens_Inhand = i;
}
int Player::getTokens_Inhand()
{
	return Tokens_Inhand;
}

void Player::setTokens_Unused(int i)
{
	Tokens_Unused = i;
}
int Player::getTokens_Unused()
{
	return Tokens_Unused;
}

void Player::setRace_Unused(Race r)
{
	Race_Unused = r;
}
Race Player::getRace_Unused()
{
	return Race_Unused;
}

void Player::setRace_Inhand(Race r)
{
	Race_Inhand = r;
}
Race Player::getRace_Inhand()
{
	return Race_Inhand;
}

void Player::setBadges_Unused(Badges b)
{
	Badges_Unused = b;
}
Badges Player::getBadges_Unused()
{
	return Badges_Unused;
}

void Player::setBadges_Inhand(Badges b)
{
	Badges_Inhand = b;
}
Badges Player::getBadges_Inhand()
{
	return Badges_Inhand;
}

void Player::setCoins_Inhand(int i)
{
	Coins_Inhand = i;
}
int Player::getCoins_Inhand()
{
	return Coins_Inhand;
}

void Player::setCoins_Unused(int i)
{
	Coins_Unused = i;
}
int Player::getCoins_Unused()
{
	return Coins_Unused;
}

void Player::setTotalScore(int i)
{
	totalScore = i;

}

int Player::getTotalScore()
{
	return totalScore;
}

bool Player::enableToPickRegion(Region region, int roundNumber, Map map)
{

	/*这有问题 需要研究规则再回来*/
	/* Check if player's race has power that can reduce token cost at a special region shape */

	if (this->getRace_Inhand().getTokenPower().compare(region.getRegionTpye()) == 0)
	{
		this->setSpecialPowerToken(this->getSpecialPowerToken() + 1);
	}
	/* Check if player's badge has power that can reduce token cost at a special region shape */

	if (this->getBadges_Inhand().getTokenPower1().compare(region.getRegionTpye()) == 0 || this->getBadges_Inhand().getTokenPower2().compare(region.getRegionTpye()) == 0)
	{
		this->setSpecialPowerToken(this->getSpecialPowerToken() + 1);
	}
	/**/


	/*if this region is empty, check whether player's token is enough */

	if (region.getRegionTpye().compare("mountain") == 0) // if this region has special shape , reset the tokenNeeded variable;
	{
		region.setTokenNeeded(3);
	}

	/*determine if  enpty regions can be conquered or not*/
	int totalToken = this->getTokens_Inhand() + this->getSpecialPowerToken() + this->getDice_Number_Inhand();
	if (region.getplayerNumber() == 0)
	{
		if (totalToken >= region.getTokenNeeded()) {
			return true;
		}
		else {
			return false;
		}
	}
	/*if this region belongs to another player, check whether player's token is enough */
	else {
		if (totalToken >= region.getCurrentOcupiedToken()) {
			return true;
		}
		else {
			return false;
		}
	}
}

void Player::pick_race(Race race[], Badges badges[])
{
	phaseObserver->method = 1;
	phaseObserver->location = 1;
	notify("PhaseObserver", playerIndex);
	cout << "--------------Please give the number of combo that you want  :----------------" << endl;
		cout << endl;
	int n = 1;
	cin >> n;         // let player choose a combo number;
					  //n = 3;
	while (n < 1 || n>6)
	{
		cout << "--------------please give a number between 1 to 6 -------------" << endl;
		cin >> n;
	}
	if (getNeedPlayerHandsObserver()) {
		notify("PlayerHandsObserverDecorator", playerIndex);
	}
	cout << "----------You have chosen :" << race[n - 1].GetRaceName() << "    " << badges[n - 1].GetBadgeName()<<"------------" << endl;

	for (int i = 0; i < n - 1; i++)  // add coin for the combos that being skipped;
	{
		race[i].SetSelect_Coin(1);
	}
	this->setCoins_Inhand(this->getCoins_Inhand() - n + 1);

	//  assign attributes to this player;====================
	if (this->getRace_Inhand().GetRaceName().compare("Null") != 0) {
		this->setRace_Unused(this->getRace_Inhand());
		this->setBadges_Unused(this->getBadges_Inhand());
		this->setTokens_Unused(this->getTokens_Inhand());
		this->setRegions_Unused(this->getRegions_Inhand());
		this->setCoins_Unused(this->getCoins_Inhand());
		this->setDice_Number_Unused(this->getDice_Number_Inhand());
		this->setSpecialPowerToken(this->getSpecialPowerToken());
		this->setUnusedRaceName(this->getRace_Unused().GetRaceName());
		this->Regions_Inhand.clear();
	}
	this->setCoins_Unused(0);
	this->setRace_Inhand(race[n - 1]);
	this->setBadges_Inhand(badges[n - 1]);
	this->setTokens_Inhand(this->getBadges_Inhand().GetBadgesTokens() + this->getRace_Inhand().GetRaceTokens());

	if (race[n - 1].GetSelect_Coin() != 0)  //If choose the combo with extra coins, initial coin increase;
	{
		this->setCoins_Inhand(this->getCoins_Inhand() + race[n - 1].GetSelect_Coin());
	}



	for (int i = n; i < 14; i++)  // shift up the following races;
	{
		race[i - 1] = race[i];
	}
	race[13] = Race();    // change the last one of the race[] into default value;

	for (int i = n; i < 20; i++)  // shift up the following badges;
	{
		badges[i - 1] = badges[i];
	}
	badges[19] = Badges();    // change the last one of the race[] into default value;
	
	
	
	cout << "Here are information for player" << this->getPlayerIndex() << ": " << endl;
	this->display();

	cout << endl;
	cout << "Here are combos of races and bagdges left after player " << this->getPlayerIndex() << " picked :" << endl;
	for (int i = 0; i < 6; i++)	// print the sequence after shuffle;
	{
		cout << "combo " << i + 1 << "     Select_Coin: " << race[i].GetSelect_Coin() << ".  RaceName:  " << race[i].GetRaceName() << ".  RaceToken: " << race[i].GetRaceTokens() << ".  BadgesName:  " << badges[i].GetBadgeName() << ".  BadgeToken:  " << badges[i].GetBadgesTokens() << endl;
	}
	cout << endl;
	cout << endl;
	phaseObserver->method = 1;
	phaseObserver->location = 2;
	notify("PhaseObserver", playerIndex);
}
void Player::conquers(Map& map, int roundNumber, vector<Player>& playerList)
{	
	phaseObserver->method = 2;
	phaseObserver->location = 1;
	notify("PhaseObserver", playerIndex);
	int subRoundCouter = 1;//subround for each player
	map.drawMap();
	map.displayRegionList();
	this->display();
	bool keepGoing = true;
	do 
	{
		if (this->getTokens_Inhand() == 0) {
			keepGoing = false;
		}
		else {
			bool needReEnter;
			char regionNumber;
			int regionIndex;
			do {
				needReEnter = false;
				if (subRoundCouter == 1 && roundNumber == 1) {
					cout << "--------Because this is you fist time to choose a Region, you can only choose from 'edge region list' : " << endl;
					cout << " [ ";
					for (int i = 0; i < map.getEdgeRegions().size(); i++)
					{
						cout << map.getEdgeRegions()[i] << ",";
					}
					cout << " ]" << endl;
				}
				cout << "-----------Please choose the Region that you want :   ----------------------" << endl;
				cin >> regionNumber;
				cout << endl;
				regionIndex = (int)regionNumber - 64;
				needReEnter = notValidInput(regionIndex, map);
				if (!needReEnter) {
					if (subRoundCouter == 1 && roundNumber == 1) {
						needReEnter = notOnTheEdges(regionNumber, map);
					}
					if (!needReEnter) {
						/* If the region is already belongs to this player, let him choose again :*/
						needReEnter = belongItself(regionIndex);
						/* Water area should not be conquered unless player has special power:*/
						if (!needReEnter) {
							needReEnter = isWaterRegion(regionIndex, map);
						}
						/* check if is Adjacent from conquered regions*/
						if (!needReEnter&&subRoundCouter != 1) {
							needReEnter = notAdjacentRegion(regionIndex);
						}
					}
				}
			} while (needReEnter);

			/*there are sufficient tokens to conquere this region :*/
			if (enableToPickRegion(map.getRegion(regionIndex), roundNumber, map)) {
				int tokenNeed = 0;
				int tokenUse;
				do {
					needReEnter = false;
					cout << "Please enter the number of tokens you want to use to conquere this region:" << endl;
					cin >> tokenUse;
					if (tokenUse > this->getTokens_Inhand()) {
						cout << "You do not have enough tokens,try again" << endl;
						needReEnter = true;
					}
					if (map.getRegion(regionIndex).getplayerNumber() == 0) {
						tokenNeed = map.getRegion(regionIndex).getTokenNeeded() - this->getSpecialPowerToken();
						if (tokenUse < tokenNeed) {
							needReEnter = true;
							cout<<"The number you entered is not enough to conquere this region,please enter again"<<endl;
						}
					}
					else {
						tokenNeed = max(map.getRegion(regionIndex).getTokenNeeded() - this->getSpecialPowerToken(), map.getRegion(regionIndex).getCurrentOcupiedToken());
						if (tokenUse < tokenNeed) {
							needReEnter = true;
							cout << "The number you entered is not enough to conquere this region,please enter again" << endl;
						}
					}
				} while (needReEnter);

				if (map.getRegion(regionIndex).getplayerNumber() != 0) {
					conquereOthers(regionIndex, map, playerList);
				}

				this->setTokens_Inhand(this->getTokens_Inhand() - tokenUse);//consume tokens in hand to conquere this region
				this->setSpecialPowerToken(0);

				/*update map*/
				map.regionList[regionIndex - 1].setplayerNumber(this->getPlayerIndex());
				map.regionList[regionIndex - 1].setCurrentOcupiedToken(tokenUse);
				map.regionList[regionIndex - 1].setOcupiedRace(this->getRace_Inhand().GetRaceName());
				this->setRegions_Inhand(map.getRegion(regionIndex));	//put this region into this player's region list;
				if (getNeedPlayerDominationObserver() && playerDominationObserverDecorator->getMethod() != 2) {
					playerDominationObserverDecorator->currentPlayerIndex = this->getPlayerIndex();
					playerDominationObserverDecorator->setMethod(1);
					notify("PlayerDominationObserverDecorator", regionIndex);
					map.notify();
				}
			}
			/*not sufficient token to conquere this region*/
			else
			{
				cout << "The tokens in your hand is not sufficient to conquere this region,please enter Y/N to choose to roll a dice or not" << endl;
				char chooseDice;
				cin >> chooseDice;
				if (chooseDice == 'Y') {
					Dice dice;
					dice.Roll();
					dice.Display();
					int tokenHold = this->getTokens_Inhand();
					this->setDice_Number_Inhand(dice.GetNumber());

					if (enableToPickRegion(map.getRegion(regionIndex), roundNumber, map))
					{
						if (map.getRegion(regionIndex).getplayerNumber() != 0) {
							conquereOthers(regionIndex, map, playerList);
						}
						this->setTokens_Inhand(0);//consume all tokens in hand
						this->setSpecialPowerToken(0);
						/*update map*/
						map.regionList[regionIndex - 1].setplayerNumber(this->getPlayerIndex());
						map.regionList[regionIndex - 1].setCurrentOcupiedToken(tokenHold);
						map.regionList[regionIndex - 1].setOcupiedRace(this->getRace_Inhand().GetRaceName());
						this->setRegions_Inhand(map.getRegion(regionIndex));	//put this region into this player's region list;
						
						if (getNeedPlayerDominationObserver()&& playerDominationObserverDecorator->getMethod() != 2) {
							playerDominationObserverDecorator->currentPlayerIndex = this->getPlayerIndex();
							playerDominationObserverDecorator->setMethod(1);
							notify("PlayerDominationObserverDecorator", regionIndex);
							map.notify();
						}
						keepGoing = false;
					}
					else {
						cout << "The dice number plus your holding tokens are not enough to conquere this region." << endl;
						keepGoing = false;
					}
					dice.Reset();//reset dice to null;
					this->setDice_Number_Inhand(dice.GetNumber());
				}
				keepGoing = false;
			}
			subRoundCouter++;
			this->display();
		}
		/*Redistribution*/
		if (!keepGoing) {
			phaseObserver->method = 2;
			phaseObserver->location = 2;
			notify("PhaseObserver", playerIndex);
		}
	}while (keepGoing);
	redistribution(map);
}
 
void Player::scores()
{
	phaseObserver->method = 3;
	phaseObserver->location = 1;
	notify("PhaseObserver",playerIndex);
	int coin = 0;

	for (int i = 0; i < this->getRegions_Inhand().size(); i++)
	{
		if (this->getRace_Inhand().getCoinPower().compare(this->getRegions_Inhand()[i].getRegionTpye()) == 0)
		{
			coin = coin + 2;
		}
		else {
			coin++;
		}
		if (this->getBadges_Inhand().getCoinPower().compare(this->getRegions_Inhand()[i].getRegionTpye()) == 0)
		{
			coin = coin + 2;
		}
		else {
			coin++;
		}
	}


	for (int i = 0; i < this->getRegions_Unused().size(); i++)
	{
		if (this->getRace_Unused().getCoinPower().compare(this->getRegions_Unused()[i].getRegionTpye()) == 0)
		{
			coin = coin + 2;
		}
		else {
			coin++;
		}
		if (this->getBadges_Unused().getCoinPower().compare(this->getRegions_Unused()[i].getRegionTpye()) == 0)
		{
			coin = coin + 2;
		}
		else {
			coin++;
		}

	}
	this->setTotalScore(coin + this->getCoins_Inhand() + this->getCoins_Unused());
	if (getNeedVictoryCoinsObserver()) {
		victoryCoinsObserverDecorator->setPlayerIndex(this->getPlayerIndex());
		notify("VictoryCoinsObserverDecorator", coin + this->getCoins_Inhand() + this->getCoins_Unused());
	}

	phaseObserver->method = 3;
	phaseObserver->location = 2;
	notify("PhaseObserver", playerIndex);
}