#include <iostream>
#include "Badges.h"

using namespace std;


Badges::Badges(int num) {
	switch (num)
	{
	case 1:
		BadgeName = "Alchemist";
		BadgesTokens = 4;
		break;
	case 2:
		BadgeName = "Berserk";
		BadgesTokens = 4;
		break;
	case 3:
		BadgeName = "Bivouacking";
		BadgesTokens = 5;
		break;
	case 4:
		BadgeName = "Commando";
		BadgesTokens = 4;
	case 5:
		BadgeName = "Dragon Master";
		BadgesTokens = 5;
		break;
	case 6:
		BadgeName = "Flying";
		BadgesTokens = 5;
		break;
	case 7:
		BadgeName = "Forest";
		BadgesTokens = 4;
		break;
	case 8:
		BadgeName = "Fortified";
		BadgesTokens = 3;
		break;
	case 9:
		BadgeName = "Heroic";
		BadgesTokens = 5;
	case 10:
		BadgeName = "Hill";
		BadgesTokens = 4;
		break;
	case 11:
		BadgeName = "Merchant";
		BadgesTokens = 2;
		break;
	case 12:
		BadgeName = "Mounted";
		BadgesTokens = 5;
		break;
	case 13:
		BadgeName = "Pillaging";
		BadgesTokens = 5;
		break;
	case 14:
		BadgeName = "Seafaring";
		BadgesTokens = 5;
		break;
	
	case 15:
		BadgeName = "Spirit";
		BadgesTokens = 5;
		break;
	case 16:
		BadgeName = "Stout";
		BadgesTokens = 4;
		break;
	case 17:
		BadgeName = "Swamp";
		BadgesTokens = 4;
		break;
	case 18:
		BadgeName = "Underworld";
		BadgesTokens = 5;
		break;
	case 19:
		BadgeName = "Wealthy";
		BadgesTokens = 4;
	case 20:
		BadgeName = "Blank Special Power badge";
		BadgesTokens = NULL;

	default:
		BadgeName = "";
		BadgesTokens = 0;
	}
}
Badges::~Badges()
{}

void Badges::display()
{
	cout << "The BadgeName is :" << BadgeName << endl;
	cout << "The  Tokens is :" << BadgesTokens << endl;
}
string Badges::GetBadgeName()
{
	return BadgeName;
}
int Badges::GetBadgesTokens()
{
	return BadgesTokens;
}



