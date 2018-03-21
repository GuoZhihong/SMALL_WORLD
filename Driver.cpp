#include"MapLoader.h"
#include "Badges.h"
#include "pieces.h"
#include "Race.h"
#include "Tokens.h"
#include <iostream>
#include "Dice.h"
#include "Player.h"
using namespace std;
Race race[14];			// create an array to store 14 races;
Badges badges[20];		// create an array to store 20 badges;
//vector<Region> regionList1;
void shuffleCardAndDisplay() {
	
	/*races and badges before shuffling*/
	for (int i = 0; i < 14; i++)	// initialize the Race array;
	{
		race[i] = Race(i + 1);
	}
	for (int j = 0; j < 20; j++)	// initialize the Badges array;
	{
		badges[j] = Badges(j + 1);
	}
	
	cout << endl;
	cout << "After shuffling-----------------------------------------" << endl;
	cout << endl;

	cout << "----------------There are the combos you can choose :----------------" << endl;
	cout << "No:      Select_Coin          RaceName               BadgesName" << endl;
	cout << endl;

	for (int i = 0; i < 14; i++)	// shuffling Race
	{
		int r = rand() % 14;
		Race temp = race[i]; race[i] = race[r]; race[r] = temp;
	}
	for (int i = 0; i < 20; i++)	// shuffling Badges
	{
		int r = rand() % 20;
		Badges temp = badges[i]; badges[i] = badges[r]; badges[r] = temp;
	}
	for (int i = 0; i < 6; i++)	// print the sequence after shuffle;
	{
		cout << i + 1 << "       " << race[i].GetSelect_Coin() << "       " << race[i].GetRaceName() << "          " << badges[i].GetBadgeName() << endl;
	}
	cout << endl;
}

/*Game logic*/
int main() {
	cout << "Welcome to Small world" << endl;
	string fileName; 
	
	//create player list
	int playerNumber;;
	cout << "Please choose the number of players:" << endl;
	cin >> playerNumber;

	switch (playerNumber)
	{
	case 2:
		fileName = "map1.txt";
		break;
	case 3:
		fileName = "map2.txt";
		break;
	case 4:
		fileName = "map3.txt";
		break;
	case 5:
		fileName = "map4.txt";
		break;
	default:
		cout << "Invalid number of players,program will be terminated" << endl;
		exit(0);
	}
	/*load map file*/
	MapLoader mapLoader;
	mapLoader.openInput(fileName);
	mapLoader.readFile();
	mapLoader.closeInput();

	/*setup map*/
	Map map =  Map(mapLoader.getM(), mapLoader.getN(), playerNumber);
	//regionList1 = mapLoader.getRegions();
	map.setRegionList(mapLoader.getRegions());
	map.drawMap();

	
	map.displayRegionList();

	/*shuffle cards*/
	shuffleCardAndDisplay();

	/*create players*/
	vector<Player> playerList;
	for (int i = 1; i <= playerNumber; i++)
	{
		Player player(i);
		playerList.push_back(player);
	}
	/*

	int gameTurn = 2;
	string chooseNewRace;
	for (int i = 0; i < gameTurn; i++) {
		cout << "Game turn  [" << i + 1 << "] start:" << endl;
		cout << endl;

		for (int j = 0; j < playerList.size(); j++) {
			cout << "please enter Y / N to choose a new race and special power combo : " << endl;
			cin >> chooseNewRace;
			if (chooseNewRace.compare("Y") == 0)
			{
				cout << "player " << playerList[j].getPlayerIndex() << " picks race and badge:" << endl;
				playerList[j].pick_race(race, badges);
				playerList[j].conquers(map, i, playerList);
				playerList[j].scores();
			}
			else
			{
				playerList[j].conquers(map, i, playerList);
				playerList[j].scores();
			}


		}

	}
	*/

	/*
	int winnernumber = 1;
	int winnerscore = playerList[0].getTotalScore();
	// get max score from player

	for (int i = 0; i < playerList.size(); i++) {

		if (playerList[i].getTotalScore() > winnerscore) {
			winnerscore = playerList[i].getTotalScore();
			winnernumber = i + 1;
		}
		cout << "Player " << playerList[i].getPlayerIndex() << " has " << playerList[i].getTotalScore() << " coins ." << endl;
	}

	cout << "-----------Game finish all turn, winner is player " << winnernumber << endl;
	*/

	

	int gameTurn = 10;
	for (int i = 0; i < gameTurn; i++) {
		cout << "Game turn  [" << i+1 << "] start:" << endl;
		cout << endl;
		for (int j = 0; j < playerList.size(); j++) {
			if (i == 0) {
				cout << "player " << playerList[j].getPlayerIndex() << " picks race and badge:" << endl;
				playerList[j].pick_race(race, badges);
			}
			else {
				cout << "player " << playerList[j].getPlayerIndex() << " turn: please enter Y/N to choose a new race and special power combo:" << endl;
				char choosenewrace;
				cin >> choosenewrace;
				if (choosenewrace == 'Y') {
					cout << "player " << playerList[j].getPlayerIndex() << " picks race and badge:" << endl;
					playerList[j].pick_race(race, badges);
				}
			}
			playerList[j].conquers(map, j, playerList);
			playerList[j].scores();
		}	
	}

	int winnernumber = playerList[0].getPlayerIndex();
	int winnerscore = playerList[0].getTotalScore();
	// get max score from player

	for (int i = 0; i < playerList.size(); i++) {

		if (playerList[i].getTotalScore() > winnerscore) {
			winnerscore = playerList[i].getTotalScore();
			winnernumber = i + 1;
		}
		cout << "Player " << playerList[i].getPlayerIndex() << " has " << playerList[i].getTotalScore() << " coins ." << endl;
	}

	cout << "-----------Game finish all turn, winner is player" << winnernumber << endl;

	system("pause");
	return 0;
}



