#include "ModeratePlayer.h"
void ModeratePlayer::execute(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[])
{
	playerList[currentPlayer - 1].notify("BasicGameStatisticsObserver", roundNumber);
	if (roundNumber == 1) {
		//cout << "player " << playerList[currentPlayer - 1].getPlayerIndex() << " picks race and badge:" << endl;
		playerList[currentPlayer - 1].pick_race(race, badges);
	}
	else {
		int getTokenFromHand = playerList[currentPlayer - 1].getTokens_Inhand();
		int getTokenFromMap = 0;
		for (int i = 0; i < playerList[currentPlayer - 1].getRegions_Inhand().size(); i++)
		{
			getTokenFromMap += playerList[currentPlayer - 1].getRegions_Inhand()[i].getCurrentOcupiedToken() - 1;
		}
		int tokenCanUsedToReSet = getTokenFromHand + getTokenFromMap;
		if (tokenCanUsedToReSet == 0&& (playerList[currentPlayer - 1].getRace_Inhand().GetRaceName() !="Ghouls"&&(roundNumber != 2|| roundNumber != 3))) {//the case for repick
			//cout << "As a Moderate player,you  picks race and badge:" << endl;
			playerList[currentPlayer - 1].pick_race(race, badges);
		}
		else {
			this->redistribution(map,playerList,currentPlayer);
		}
	}
	this->conquers(map, roundNumber, playerList, currentPlayer);
	playerList[currentPlayer - 1].scores();
}
void ModeratePlayer::conquers(Map& map, int roundNumber, vector<Player>& playerList, int currentPlayer)
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
				cin >> regionNumber;
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
				int tokenUse;
				do {
					needReEnter = false;
					cout << "Please enter the number of tokens you want to use to conquere this region:" << endl;
					cin >> tokenUse;
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
				cin >> chooseDice;
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
void ModeratePlayer::redistribution(Map& map, vector<Player>& playerList, int currentPlayer)
{
	int getTokenFromHand = playerList[currentPlayer - 1].getTokens_Inhand();
	int getTokenFromMap = 0;
	for (int i = 0; i < playerList[currentPlayer - 1].getRegions_Inhand().size(); i++)
	{
		getTokenFromMap += playerList[currentPlayer - 1].getRegions_Inhand()[i].getCurrentOcupiedToken() - 1;
	}
	int tokenCanUsedToReSet = getTokenFromHand + getTokenFromMap;
	playerList[currentPlayer - 1].setTokens_Inhand(tokenCanUsedToReSet);
	for (int i = 0; i < playerList[currentPlayer - 1].getRegions_Inhand().size(); i++)
	{
		int currentRegion = playerList[currentPlayer - 1].getRegions_Inhand()[i].getNodeNumber();
		playerList[currentPlayer - 1].Regions_Inhand[i].setCurrentOcupiedToken(1);
		map.regionList[currentRegion - 1].setCurrentOcupiedToken(1);
	}
}
