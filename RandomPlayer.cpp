#include "RandomPlayer.h"

void RandomPlayer::execute(vector<Player>& playerList, Map & map, int currentPlayer, int roundNumber, Race race[], Badges badges[])
{
	playerList[currentPlayer - 1].notify("BasicGameStatisticsObserver", roundNumber);
	if (roundNumber == 1) {	
		playerList[currentPlayer-1].pick_race(race, badges);
	}
	else {
		cout << "In order to gather the tokens you can use to conquere for this round,please do the redistribution." << endl;
		playerList[currentPlayer - 1].redistribution(map);
		cout << "player " << playerList[currentPlayer - 1].getPlayerIndex() << " as a random player: please enter Y/N to choose a new race and special power combo:" << endl;
		char choosenewrace;
		bool validNumber = false;
		while (!validNumber) {
			try {
				cin >> choosenewrace;
				if (choosenewrace!='Y' && choosenewrace != 'N') {  //check if the input is valid;
					throw domain_error("Invaild input. Please enter again:(Y or N)");
				}
				validNumber = true;
			}
			catch (exception& e) {
				cout << "Standard exception: " << e.what() << endl;
			}
		}
		if (choosenewrace == 'Y') {
			//cout << "player " << playerList[currentPlayer - 1].getPlayerIndex() << " picks race and badge:" << endl;
			playerList[currentPlayer - 1].pick_race(race, badges);
		}
	}
	playerList[currentPlayer - 1].conquers(map, roundNumber, playerList);
	playerList[currentPlayer - 1].scores();
}
