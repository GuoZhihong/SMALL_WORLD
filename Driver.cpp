#include"MapLoader.h"
#include "Badges.h"
#include "pieces.h"
#include "Race.h"
#include "Tokens.h"
#include <iostream>
#include "Dice.h"
#include "Player.h"
#include"AggressivePlayer.h"
#include"DefensivePlayer.h"
#include"ModeratePlayer.h"
#include"RandomPlayer.h"
#include"GameStatisticsObserver.h"
#include"PlayerDominationObserverDecorator.h"
#include"VictoryCoinsObserverDecorator.h"
#include"PlayerHandsObserverDecorator.h"
#include"BasicGameStatisticsObserver.h"
#include<ctime>
#include<cstdlib>
#include <exception>
using namespace std;



Race race[14];			// create an array to store 14 races;
Badges badges[20];		// create an array to store 20 badges;
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
		cout << "combo " << i + 1 << "     Select_Coin: " << race[i].GetSelect_Coin() << ".  RaceName:  " << race[i].GetRaceName() << ".  RaceToken: " << race[i].GetRaceTokens() << ".  BadgesName:  " << badges[i].GetBadgeName() << ".  BadgeToken:  " << badges[i].GetBadgesTokens() << endl;
	}
	cout << endl;
}
bool needDecorator(int i,Player* player) {
	if (i == 1) {
		
		cout << "please specify if you want Observer Decorators or not by Y/N" << endl;
		char needDecorator;
		bool validNumber = false;
		while (!validNumber) {
			try {
				cin >> needDecorator;
				if (needDecorator != 'Y'&& needDecorator != 'N') {  //check if the input is valid;
					cout << needDecorator << endl;
					throw domain_error("Invaild input. Please enter again:(Y or N)");
				}
				validNumber = true;
			}
			catch (exception& e) {
				cout << "Standard exception: " << e.what() << endl;
			}
		}
		if (needDecorator == 'Y') {
			player->setNeedDecorator('Y');
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (player->getNeedDecorator() == 'Y') {
			return true;
		}
		else {
			return false;
		}
	}
}
bool hasDecorator(Player player) {
	if (player.getNeedDecorator() == 'N') {
		return false;
	}
	else {
		return true;
	}
	
}
/*Game logic*/
int main() {

	cout << "Welcome to Small world" << endl;
	string fileName; 
	
	//create player list
	int playerNumber;;
	cout << "Please choose the number of players:" << endl;
	bool validNumber = false;
	while (!validNumber) {
		try {
			cin >> playerNumber;

			if (cin.fail()) {//check if user input is an integer;
				cin.clear();
				cin.ignore();
				throw domain_error("Not an integer,Please enter again: ");
			}
			if (playerNumber > 5 || playerNumber < 2) {  //check if user inpu between 2-5 ;
				throw domain_error("Invaild input. Please enter again:");
			}
			validNumber = true;
		}
		catch (exception& e) {
			cout << "Standard exception: " << e.what() << endl;
		}
	}
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
	map.setRegionList(mapLoader.getRegions());
	GameStatisticsObserver gameStatisticsObserver(&map);
	map.drawMap();

	
	map.displayRegionList();

	/*shuffle cards*/
	shuffleCardAndDisplay();

	/*create players*/
	vector<Player> playerList;
	int playerType;
	for (int i = 1; i <= playerNumber; i++)
	{
		cout << "Player " << i << " please indicate which kind of player you are from following types" << endl;
		cout << "(1) An aggressive player" << endl;
		cout << "(2) A defensive player" << endl;
		cout << "(3) A moderate player" << endl;
		cout << "(4) A random player" << endl;
		validNumber = false;
		while (!validNumber) {
			try {
				cin >> playerType;

				if (cin.fail()) {//check if user input is an integer;
					cin.clear();
					cin.ignore();
					throw domain_error("Not an integer,Please enter again: ");
				}
				if (playerType > 4 || playerType < 1) {  //check if user inpu between 1-4 ;
					throw domain_error("Invaild input. Please enter again:");
				}
				validNumber = true;
			}
			catch (exception& e) {
				cout << "Standard exception: " << e.what() << endl;
			}
		}
		Player player;
		switch (playerType)
		{
		case 1:
			player = Player(i, new AggressivePlayer());
			cout << "You are An aggressive player now" << endl;
			break;
		case 2:
			player = Player(i,new DefensivePlayer());
			cout << "You are A defensive player now" << endl;
			break;
		case 3:
			player = Player(i,new ModeratePlayer());
			cout << "You are A moderate player now" << endl;
			break;
		case 4:
			player = Player(i,new RandomPlayer());
			cout << "You are A random player now" << endl;
			break;
		default:
			cout << "No such type of player" << endl;
			exit(0);
		}

		playerList.push_back(player);
	}
	int gameTurn;

	switch (playerNumber)
	{
	case 2:
		gameTurn = 10;
		break;
	case 3:
		gameTurn = 10;
		break;
	case 4:
		gameTurn = 9;
		break;
	case 5:
		gameTurn = 8;
		break;
	default:
		exit(0);
	}
	for (int i = 1; i <= gameTurn; i++) {
		for (int j = 0; j < playerList.size(); j++) {
			map.notify();
			cout << "Player " << playerList[j].getPlayerIndex() << endl;
			if (needDecorator(i,&playerList[j])) {
				bool counter = true;
				do {
					cout << "Please choose the Observer Decorator you want from following choices 1 to 3,enter 0 if you don't want more" << endl;
					cout << "1.Player Domination Observer Decorator" << endl;
					cout << "2.Player Hands Observer Decorator" << endl;
					cout << "3.Victory Coins Observer Decorator" << endl;
					int decoratorChoice;
					try {
						cin >> decoratorChoice;
						if (cin.fail()) {//check if user input is an integer;
							cin.clear();
							cin.ignore();
							throw domain_error("Not an integer,Please enter again: ");
						}
						if (decoratorChoice > 3 || decoratorChoice < 0) {  //check if user input between 0-3 ;
							throw domain_error("Invaild input. Please enter again:");
						}
					}
					catch (exception& e) {
						cout << "Standard exception: " << e.what() << endl;
					}
					switch (decoratorChoice)
					{
					case 0:
						counter = false;
						break;
					case 1:
						if (playerList[j].getNeedPlayerDominationObserver()) {
							cout << "You already have had this type of observer,please choose again" << endl;
						}
						else {
							playerList[j].setNeedPlayerDominationObserver(true);
						}
						break;
					case 2:
						if (playerList[j].getNeedPlayerHandsObserver()) {
							cout << "You already have had this type of observer,please choose again" << endl;
						}
						else {
							playerList[j].setNeedPlayerHandsObserver(true);
						}
						break;
					case 3:
						if (playerList[j].getNeedVictoryCoinsObserver()) {
							cout << "You already have had this type of observer,please choose again" << endl;
						}
						else {
							playerList[j].setNeedVictoryCoinsObserver(true);
						}
						break;
					default:
						break;
					}
				} while (counter);
			}
			playerList[j].executeStrategy(playerList,map,playerList[j].getPlayerIndex(),i,race,badges);
			if (hasDecorator(playerList[j])) {
				bool counter = true;
				do {
					cout << "Please choose the Observer Decorator you do not want anymore from following choices 1 to 3,enter 0 if you don't want more" << endl;
					cout << "1.Player Domination Observer Decorator" << endl;
					cout << "2.Player Hands Observer Decorator" << endl;
					cout << "3.Victory Coins Observer Decorator" << endl;
					int decoratorChoice;
					try {
						cin >> decoratorChoice;
						if (cin.fail()) {//check if user input is an integer;
							cin.clear();
							cin.ignore();
							throw domain_error("Not an integer,Please enter again: ");
						}
						if (decoratorChoice > 3 || decoratorChoice < 0) {  //check if user input between 1-3 ;
							throw domain_error("Invaild input. Please enter again:");
						}
					}
					catch (exception& e) {
						cout << "Standard exception: " << e.what() << endl;
					}
					
					switch (decoratorChoice)
					{
					case 0:
						counter = false;
						break;
					case 1:
						if (playerList[j].getNeedPlayerDominationObserver()) {
							playerList[j].setNeedPlayerDominationObserver(false);
							playerList[j].Detach(1);
						}
						else {
							cout<<"You do not have this type of observer,please choose again"<<endl;
						}
						break;
					case 2:
						if (playerList[j].getNeedPlayerHandsObserver()) {
							playerList[j].setNeedPlayerHandsObserver(false);
							playerList[j].Detach(2);
						}
						else {
							cout << "You do not have this type of observer,please choose again" << endl;
						}
						break;
					case 3:
						if (playerList[j].getNeedVictoryCoinsObserver()) {
							playerList[j].setNeedVictoryCoinsObserver(false);
							playerList[j].Detach(3);
						}
						else {
							cout << "You do not have this type of observer,please choose again" << endl;
						}
						break;
					default:
						break;
					}
				} while (counter);
			}
			cout << endl;
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



