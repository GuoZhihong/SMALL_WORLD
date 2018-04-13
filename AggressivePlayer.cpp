#include "AggressivePlayer.h"

void AggressivePlayer::execute(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[])
{	
	playerList[currentPlayer - 1].notify("BasicGameStatisticsObserver", roundNumber);
	if (roundNumber == 1) {
		this->pick_race(race, badges,playerList,currentPlayer);
	}
	else {
		this->redistribution(map,playerList,currentPlayer);
		cout << "player " << playerList[currentPlayer - 1].getPlayerIndex() << " is an agressive player,so his/her hold onto everything he/she got until the end of the game.(NO-repick combo of race and badges)" << endl;
		cout << endl;
	}
	this->conquers(map, roundNumber, playerList,currentPlayer);
	playerList[currentPlayer - 1].scores();
}
void AggressivePlayer::pick_race(Race race[], Badges badges[], vector<Player>& playerList, int currentPlayer)
{
	playerList[currentPlayer - 1].phaseObserver->method = 1;
	playerList[currentPlayer - 1].phaseObserver->location = 1;
	playerList[currentPlayer - 1].notify("PhaseObserver", currentPlayer);

	int comboTokenSum = race[0].GetRaceTokens() + badges[0].GetBadgesTokens();
	vector<int> maxCombo;
	for (int i = 0; i < 6; i++)
	{
		comboTokenSum = max(comboTokenSum, race[i].GetRaceTokens() + badges[i].GetBadgesTokens());
	}
	for (int i = 0; i < 6; i++)
	{
		if (comboTokenSum == race[i].GetRaceTokens() + badges[i].GetBadgesTokens()) {
			maxCombo.push_back(i + 1);
		}
	}

	cout << "As an aggressive player,you need to expand your regions as quick as you can ,so the maximum number of tokens combo and it's number of tokens are " << endl;
	for (int i = 0; i < maxCombo.size(); i++)
	{
		cout << "combo:" << maxCombo[i] << " Tokens:" << comboTokenSum << endl;
	}
	cout << endl;
	int n;
	bool count;
	do {
		count = true;
		bool validNumber = false;
		while (!validNumber) {
			try {
				cin >> n;   // let player choose a combo number;

				if (cin.fail()) {//check if user input is an integer;
					cin.clear();
					cin.ignore();
					throw domain_error("Not an integer,Please enter again: ");
				}
				if (n > 6 || n < 1) {  //check if user inpu between 1-6 ;
					throw domain_error("Invaild input. Please enter again:");
				}
				validNumber = true;
			}
			catch (exception& e) {
				cout << "Standard exception: " << e.what() << endl;
			}
		}
		for (int i = 0; i < maxCombo.size(); i++)
		{
			if (n == maxCombo[i]) {
				count = false;
				break;
			}
			else {
				cout << "Please choose the maximum combo." << endl;
				break;
			}
		}
	} while (count);

	if (playerList[currentPlayer - 1].getNeedPlayerHandsObserver()) {
		playerList[currentPlayer - 1].notify("PlayerHandsObserverDecorator", currentPlayer);
	}
	cout << "----------You have chosen :" << race[n - 1].GetRaceName() << "    " << badges[n - 1].GetBadgeName() << endl;
	

	for (int i = 0; i < n - 1; i++)  // add coin for the combos that being skipped;
	{
		race[i].SetSelect_Coin(1);
	}
	this->setCoins_Inhand(playerList[currentPlayer - 1].getCoins_Inhand() - n + 1);

	//  assign attributes to this player;====================
	if (playerList[currentPlayer - 1].getRace_Inhand().GetRaceName().compare("Null") != 0) {
		playerList[currentPlayer - 1].setRace_Unused(playerList[currentPlayer-1].getRace_Inhand());
		playerList[currentPlayer-1].setBadges_Unused(playerList[currentPlayer-1].getBadges_Inhand());
		playerList[currentPlayer-1].setTokens_Unused(playerList[currentPlayer-1].getTokens_Inhand());
		playerList[currentPlayer-1].setRegions_Unused(playerList[currentPlayer-1].getRegions_Inhand());
		playerList[currentPlayer-1].setCoins_Unused(playerList[currentPlayer-1].getCoins_Inhand());
		playerList[currentPlayer-1].setDice_Number_Unused(playerList[currentPlayer-1].getDice_Number_Inhand());
		playerList[currentPlayer-1].setSpecialPowerToken(playerList[currentPlayer-1].getSpecialPowerToken());
		playerList[currentPlayer-1].setUnusedRaceName(playerList[currentPlayer-1].getRace_Unused().GetRaceName());
		vector<Region> tempList;
		playerList[currentPlayer-1].setRegions_Inhand(tempList);
	}

	playerList[currentPlayer - 1].setCoins_Unused(0);
	playerList[currentPlayer - 1].setRace_Inhand(race[n - 1]);
	playerList[currentPlayer - 1].setBadges_Inhand(badges[n - 1]);
	playerList[currentPlayer - 1].setTokens_Inhand(playerList[currentPlayer - 1].getBadges_Inhand().GetBadgesTokens() + playerList[currentPlayer - 1].getRace_Inhand().GetRaceTokens());

	if (race[n - 1].GetSelect_Coin() != 0)  //If choose the combo with extra coins, initial coin increase;
	{
		playerList[currentPlayer - 1].setCoins_Inhand(playerList[currentPlayer - 1].getCoins_Inhand() + race[n - 1].GetSelect_Coin());
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
	cout << "Here are information for player" << playerList[currentPlayer - 1].getPlayerIndex() << ": " << endl;
	playerList[currentPlayer - 1].display();
	cout << endl;
	cout << "Here are combos of races and bagdges left after player " << playerList[currentPlayer - 1].getPlayerIndex() << " picked :" << endl;
	for (int i = 0; i < 6; i++)	// print the sequence after shuffle;
	{
		cout << "combo " << i + 1 << "     Select_Coin: " << race[i].GetSelect_Coin() << ".  RaceName:  " << race[i].GetRaceName() << ".  RaceToken: " << race[i].GetRaceTokens() << ".  BadgesName:  " << badges[i].GetBadgeName() << ".  BadgeToken:  " << badges[i].GetBadgesTokens() << endl;
	}
	cout << endl;
	cout << endl;

	playerList[currentPlayer - 1].phaseObserver->method = 1;
	playerList[currentPlayer - 1].phaseObserver->location = 2;
	playerList[currentPlayer - 1].notify("PhaseObserver", currentPlayer);
}
void AggressivePlayer::conquers(Map& map, int roundNumber, vector<Player>& playerList, int currentPlayer)
{
	playerList[currentPlayer - 1].phaseObserver->method = 2;
	playerList[currentPlayer - 1].phaseObserver->location = 1;
	playerList[currentPlayer - 1].notify("PhaseObserver", currentPlayer);

	int getTokenFormCombo = playerList[currentPlayer - 1].getTokens_Inhand();
	int subRoundCouter = 1;//subround for each player
	map.drawMap();
	map.displayRegionList();
	playerList[currentPlayer - 1].display();
	bool keepGoing = true;
	do
	{
		if (playerList[currentPlayer - 1].getTokens_Inhand() == 0) {
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
				bool validNumber = false;
				while (!validNumber) {
					try {
						cin >> regionNumber;

						if (cin.fail()) {//check if user input is an integer;
							cin.clear();
							cin.ignore();
							throw domain_error("Not an integer,Please enter again: ");
						}
						if (regionNumber < 1) {  //check if user inpu between 2-5 ;
							throw domain_error("Invaild input. Please enter again:");
						}
						validNumber = true;
					}
					catch (exception& e) {
						cout << "Standard exception: " << e.what() << endl;
					}
				}
				cout << endl;
				regionIndex = (int)regionNumber - 64;
				needReEnter = notValidInput(regionIndex, map);
				if (!needReEnter) {
					if (subRoundCouter == 1 && roundNumber == 1) {
						needReEnter = playerList[currentPlayer - 1].notOnTheEdges(regionNumber, map);
					}
					if (!needReEnter) {
						/* If the region is already belongs to this player, let him choose again :*/
						needReEnter = playerList[currentPlayer - 1].belongItself(regionIndex);
						/* Water area should not be conquered unless player has special power:*/
						if (!needReEnter) {
							needReEnter = playerList[currentPlayer - 1].isWaterRegion(regionIndex, map);
						}
						/* check if is Adjacent from conquered regions*/
						if (!needReEnter&&subRoundCouter != 1) {
							needReEnter = playerList[currentPlayer - 1].notAdjacentRegion(regionIndex);
						}
					}
				}
			} while (needReEnter);

			/*there are sufficient tokens to conquere this region :*/
			if (playerList[currentPlayer - 1].enableToPickRegion(map.getRegion(regionIndex), roundNumber, map)) {
				int tokenNeed = 0;
				int tokenUse=0;
				do {
					needReEnter = false;
					cout << "Please enter the number of tokens you want to use to conquere this region:" << endl;
					
					bool validNumber = false;
					while (!validNumber) {
						try {
							cin >> tokenUse;			
							if (cin.fail()) {//check if user input is an integer;
								cin.clear();
								cin.ignore();
								throw domain_error("Not an integer,Please enter again: ");
							}
							if ( tokenUse < 1) {  //check if the input is valid;
								throw domain_error("Invaild input. Please enter again:");
							}
							validNumber = true;
						}
						catch (exception& e) {
							cout << "Standard exception: " << e.what() << endl;
						}
					}
					if (tokenUse > playerList[currentPlayer - 1].getTokens_Inhand()) {
						cout << "You do not have enough tokens,try again" << endl;
						needReEnter = true;
					}
					if (map.getRegion(regionIndex).getplayerNumber() == 0) {
						tokenNeed = map.getRegion(regionIndex).getTokenNeeded() - playerList[currentPlayer - 1].getSpecialPowerToken();
						if (tokenUse < tokenNeed) {
							needReEnter = true;
							cout << "The number you entered is not enough to conquere this region,please enter again" << endl;
						}
					}
					else {
						tokenNeed = max(map.getRegion(regionIndex).getTokenNeeded() - playerList[currentPlayer - 1].getSpecialPowerToken(), map.getRegion(regionIndex).getCurrentOcupiedToken());
						if (tokenUse < tokenNeed) {
							needReEnter = true;
							cout << "The number you entered is not enough to conquere this region,please enter again" << endl;
						}
					}
				} while (needReEnter);

				if (map.getRegion(regionIndex).getplayerNumber() != 0) {
					playerList[currentPlayer - 1].conquereOthers(regionIndex, map, playerList);
				}

				playerList[currentPlayer - 1].setTokens_Inhand(playerList[currentPlayer - 1].getTokens_Inhand() - tokenUse);//consume tokens in hand to conquere this region
				playerList[currentPlayer - 1].setSpecialPowerToken(0);
				/*update map*/
				map.regionList[regionIndex - 1].setplayerNumber(playerList[currentPlayer - 1].getPlayerIndex());
				map.regionList[regionIndex - 1].setCurrentOcupiedToken(tokenUse);
				map.regionList[regionIndex - 1].setOcupiedRace(playerList[currentPlayer - 1].getRace_Inhand().GetRaceName());
				playerList[currentPlayer - 1].setRegions_Inhand(map.getRegion(regionIndex));	//put this region into this player's region list;

				if (playerList[currentPlayer - 1].getNeedPlayerDominationObserver() && playerList[currentPlayer - 1].playerDominationObserverDecorator->getMethod() != 2) {
					playerList[currentPlayer - 1].playerDominationObserverDecorator->currentPlayerIndex = playerList[currentPlayer - 1].getPlayerIndex();
					playerList[currentPlayer - 1].playerDominationObserverDecorator->setMethod(1);
					playerList[currentPlayer - 1].notify("PlayerDominationObserverDecorator", regionIndex);
					map.notify();
				}
			}
			/*not sufficient token to conquere this region*/
			else
			{
				cout << "The tokens in your hand is not sufficient to conquere this region,please enter Y/N to choose to roll a dice or not" << endl;
				char chooseDice;
			
				bool validNumber = false;
				while (!validNumber) {
					try {
						cin >> chooseDice;
						if (chooseDice != 'Y' && chooseDice != 'N') {  //check if the input is valid;
							
							throw domain_error("Invaild input. Please enter again:(Y or N)");
						}
						validNumber = true;
					}
					catch (exception& e) {
						cout << "Standard exception: " << e.what() << endl;
					}
				}
				if (chooseDice == 'Y') {
					Dice dice;
					dice.Roll();
					dice.Display();
					int tokenHold = playerList[currentPlayer - 1].getTokens_Inhand();
					playerList[currentPlayer - 1].setDice_Number_Inhand(dice.GetNumber());

					if (playerList[currentPlayer - 1].enableToPickRegion(map.getRegion(regionIndex), roundNumber, map))
					{
						if (map.getRegion(regionIndex).getplayerNumber() != 0) {
							playerList[currentPlayer - 1].conquereOthers(regionIndex, map, playerList);
						}
						playerList[currentPlayer - 1].setTokens_Inhand(0);//consume all tokens in hand
						playerList[currentPlayer - 1].setSpecialPowerToken(0);
						/*update map*/
						map.regionList[regionIndex - 1].setplayerNumber(playerList[currentPlayer - 1].getPlayerIndex());
						map.regionList[regionIndex - 1].setCurrentOcupiedToken(tokenHold);
						map.regionList[regionIndex - 1].setOcupiedRace(playerList[currentPlayer - 1].getRace_Inhand().GetRaceName());
						playerList[currentPlayer - 1].setRegions_Inhand(map.getRegion(regionIndex));	//put this region into this player's region list;

						if (playerList[currentPlayer - 1].getNeedPlayerDominationObserver() && playerList[currentPlayer - 1].playerDominationObserverDecorator->getMethod() != 2) {
							playerList[currentPlayer - 1].playerDominationObserverDecorator->currentPlayerIndex = playerList[currentPlayer - 1].getPlayerIndex();
							playerList[currentPlayer - 1].playerDominationObserverDecorator->setMethod(1);
							playerList[currentPlayer - 1].notify("PlayerDominationObserverDecorator", regionIndex);
							map.notify();
						}
						keepGoing = false;
					}
					else {
						cout << "The dice number plus your holding tokens are not enough to conquere this region." << endl;
						keepGoing = false;
					}
					dice.Reset();//reset dice to null;
					playerList[currentPlayer - 1].setDice_Number_Inhand(dice.GetNumber());
				}
				keepGoing = false;
			}
			subRoundCouter++;
			playerList[currentPlayer - 1].display();
		}
		/*Redistribution*/
		if (!keepGoing) {
			playerList[currentPlayer - 1].phaseObserver->method = 2;
			playerList[currentPlayer - 1].phaseObserver->location = 2;
			playerList[currentPlayer - 1].notify("PhaseObserver", currentPlayer);
		}
	} while (keepGoing);
	playerList[currentPlayer - 1].redistribution(map);
}
void AggressivePlayer::redistribution(Map& map, vector<Player>& playerList, int currentPlayer)
{
	if (playerList[currentPlayer - 1].getRegions_Inhand().size() == 0) {
		return;
	}
	int getTokenFromHand = playerList[currentPlayer - 1].getTokens_Inhand();
	int getTokenFromMap = 0;
	for (int i = 0; i < playerList[currentPlayer - 1].getRegions_Inhand().size(); i++)
	{
		getTokenFromMap += playerList[currentPlayer - 1].getRegions_Inhand()[i].getCurrentOcupiedToken() - 1;
	}
	cout << "In order to conquere as many and quick as you can,each region leaves only one token,and rest of then to be used to conquere more regions" << endl;
	int tokenCanUsedToReSet = getTokenFromHand + getTokenFromMap;
	playerList[currentPlayer - 1].setTokens_Inhand(tokenCanUsedToReSet);
	for (int i = 0; i < playerList[currentPlayer - 1].getRegions_Inhand().size(); i++)
	{
		int currentRegion = playerList[currentPlayer - 1].getRegions_Inhand()[i].getNodeNumber();
		playerList[currentPlayer - 1].Regions_Inhand[i].setCurrentOcupiedToken(1);
		map.regionList[currentRegion - 1].setCurrentOcupiedToken(1);
	}
}

