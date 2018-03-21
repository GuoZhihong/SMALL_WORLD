#include <iostream>
#include <string>
#include "Race.h"
using namespace std;


	
	void Race::display()
	{
		cout << "The RaceName is :"<< RaceName << endl;
		cout << "The  Tokens is :" << RaceTokens << endl;
	}

	string Race::GetRaceName()
	{
		return RaceName;
	}

	void Race::setCoinPower(string cpower)
	{
		this->coinPower = cpower;
	}
	string Race::getCoinPower()
	{
		return coinPower;
	}

	void Race::setTokenPower(string tpower)
	{
		this->tokenPower = tpower;
	}

	string Race::getTokenPower()
	{
		return tokenPower;
	}

	void Race::SetSelect_Coin(int i)
	{
		this->Select_Coin = Select_Coin + i;
	}
	int Race::GetRaceTokens()
	{
		return RaceTokens;
	}
	int Race::GetSelect_Coin()
	{
		return Select_Coin;
	}

Race::Race() {
		RaceName = "N/A";
		RaceTokens = 0;
}
Race::Race(int num) {
	switch (num)
	{
	case 7 :
		RaceName = "Amazons";
		RaceTokens = 6;
		break;
	case 3 :
		RaceName = "Dwarves";
		RaceTokens = 3;
		break;
	case 8:
		RaceName = "Elves";
		RaceTokens = 6;
		break;
	case 4:
		RaceName = "Giants";
		RaceTokens = 6;		
		break;
	case 5:
		RaceName = "Ghouls";
		RaceTokens = 5;
		break;
	case 6:
		RaceName = "Halflings";
		RaceTokens = 6;
		break;
	case 1:
		RaceName = "Humans";
		RaceTokens = 5;
		coinPower = "farmland";
		break;
	case 2:
		RaceName = "Orcs";
		RaceTokens = 5;
		break;
	case 9:
		RaceName = "Ratmen";
		RaceTokens = 8;
		break;
	case 10:
		RaceName = "Skeletons";
		RaceTokens = 6;
		break;
	case 11:
		RaceName = "Sorcerers";
		RaceTokens = 5;
		break;
	case 12:
		RaceName = "Tritons";
		RaceTokens = 6;
		break;
	case 13:
		RaceName = "Trolls";
		RaceTokens = 5;
		break;
	case 14:
		RaceName = "Wizards";
		RaceTokens = 8;
		break;
		
	default:
		RaceName = "";
		RaceTokens = 0;
	}
}
Race::~Race()
{
}


