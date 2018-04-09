#include "GameStatisticsObserver.h"

void GameStatisticsObserver::update(int y)
{
	int wildRegion = 0;
	if (((Map*)getSubject())->getRegionList().size() == 23) {
		int player1 = 0;
		int player2 = 0;

		for (int i = 0; i < ((Map*)getSubject())->getRegionList().size(); i++)
		{
			if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 0)
			{
				wildRegion++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 1)
			{
				player1++;
			}
			else
			{
				player2++;
			}
		}

		cout << endl;
		cout << endl;
		cout << "---------------This is Part2:Game Statistics Observer----------------" << endl;
		cout << endl;

		cout << "There are " << ((Map*)getSubject())->getRegionList().size() << " regions in the map." << endl;

		cout << "Now wild regions are " << wildRegion << ", they are " << wildRegion * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < wildRegion; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 1's regions are " << player1 << ", they are " << player1 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player1; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 2's regions are " << player2 << ", they are " << player2 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player2; i++)
		{
			cout << "*";
		}
	}
	else if (((Map*)getSubject())->getRegionList().size() == 30) {
		int player1 = 0;
		int player2 = 0;
		int player3 = 0;
		for (int i = 0; i < ((Map*)getSubject())->getRegionList().size(); i++)
		{
			if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 0)
			{
				wildRegion++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 1)
			{
				player1++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 2)
			{
				player2++;
			}
			else
			{
				player3++;
			}
		}

		cout << endl;
		cout << endl;
		cout << "---------------This is Part2:Game Statistics Observer----------------" << endl;
		cout << endl;

		cout << "There are " << ((Map*)getSubject())->getRegionList().size() << " regions in the map." << endl;

		cout << "Now wild regions are " << wildRegion << ", they are " << wildRegion * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < wildRegion; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 1's regions are " << player1 << ", they are " << player1 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player1; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 2's regions are " << player2 << ", they are " << player2 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player2; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 3's regions are " << player3 << ", they are " << player3 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player3; i++)
		{
			cout << "*";
		}
	}
	else if (((Map*)getSubject())->getRegionList().size() == 39) {
		int player1 = 0;
		int player2 = 0;
		int player3 = 0;
		int player4 = 0;
		for (int i = 0; i < ((Map*)getSubject())->getRegionList().size(); i++)
		{
			if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 0)
			{
				wildRegion++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 1)
			{
				player1++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 2)
			{
				player2++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 3)
			{
				player3++;
			}
			else {
				player4++;
			}
		}

		cout << endl;
		cout << endl;
		cout << "---------------This is Part2:Game Statistics Observer----------------" << endl;
		cout << endl;

		cout << "There are " << ((Map*)getSubject())->getRegionList().size() << " regions in the map." << endl;

		cout << "Now wild regions are " << wildRegion << ", they are " << wildRegion * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < wildRegion; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 1's regions are " << player1 << ", they are " << player1 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player1; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 2's regions are " << player2 << ", they are " << player2 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player2; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 3' regions are " << player3 << ", they are " << player3 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player3; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 4' regions are " << player4 << ", they are " << player4 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player4; i++)
		{
			cout << "*";
		}
	}
	else {
		int player1 = 0;
		int player2 = 0;
		int player3 = 0;
		int player4 = 0;
		int player5 = 0;
		for (int i = 0; i < ((Map*)getSubject())->getRegionList().size(); i++)
		{
			if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 0)
			{
				wildRegion++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 1)
			{
				player1++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 2)
			{
				player2++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 3)
			{
				player3++;
			}
			else if (((Map*)getSubject())->getRegionList()[i].getplayerNumber() == 4)
			{
				player4++;
			}
			else
			{
				player5++;
			}
		}

		cout << endl;
		cout << endl;
		cout << "---------------This is Part2:Game Statistics Observer----------------" << endl;
		cout << endl;

		cout << "There are " << ((Map*)getSubject())->getRegionList().size() << " regions in the map." << endl;

		cout << "Now wild regions are " << wildRegion << ", they are " << wildRegion * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < wildRegion; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 1's regions are " << player1 << ", they are " << player1 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player1; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 2's regions are " << player2 << ", they are " << player2 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player2; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 3's regions are " << player3 << ", they are " << player3 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player3; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 4's regions are " << player4 << ", they are " << player4 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player4; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "Now player 5's regions are " << player5 << ", they are " << player5 * 100 / ((Map*)getSubject())->getRegionList().size() << "% : ";
		for (int i = 0; i < player5; i++)
		{
			cout << "*";
		}
	}
	cout << endl;
	cout << endl;
	cout << endl;
}