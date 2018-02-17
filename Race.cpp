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
	int Race::GetRaceTokens()
	{
		return RaceTokens;
	}


Race::Race(int num) {
	switch (num)
	{
	case 1 :
		RaceName = "Amazons";
		RaceTokens = 6;
		break;
	case 2 :
		RaceName = "Dwarves";
		RaceTokens = 3;
		break;
	case 3:
		RaceName = "Elves";
		RaceTokens = 6;
		break;
	case 4:
		RaceName = "Ghouls";
		RaceTokens = 5;
	case 5:
		RaceName = "Giants";
		RaceTokens = 6;
		break;
	case 6:
		RaceName = "Halflings";
		RaceTokens = 6;
		break;
	case 7:
		RaceName = "Humans";
		RaceTokens = 5;
		break;
	case 8:
		RaceName = "Orcs";
		RaceTokens = 5;
		break;
	case 9:
		RaceName = "Ratmen";
		RaceTokens = 8;
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
		
	default:
		RaceName = "";
		RaceTokens = 0;
	}
}
Race::~Race()
{}


