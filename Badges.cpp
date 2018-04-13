#include <iostream>
#include "Badges.h"

using namespace std;

Badges::Badges()
{
	BadgeName = "N/A";
	BadgesTokens = 0;
}
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
		break;
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
		coinPower = "forest";
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
		coinPower = "hill";
		break;
	case 11:
		BadgeName = "Merchant";
		BadgesTokens = 2;
		break;
	case 12:
		BadgeName = "Mounted";
		BadgesTokens = 5;
		tokenPower1= "hill";
		tokenPower2 = "farmland";
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
		coinPower = "swamp";
		break;
	case 18:
		BadgeName = "Underworld";
		BadgesTokens = 5;
		tokenPower1 = "cavern";
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
{
}

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

void Badges::setCoinPower(string s)
{
	coinPower = s;
}

string Badges::getCoinPower()
{
	return coinPower;
}

void Badges::setTokenPower1(string s)
{
	tokenPower1 = s;
}

string Badges::getTokenPower1()
{
	return tokenPower1;
}

void Badges::setTokenPower2(string s)
{
	tokenPower2 = s;
}

string Badges::getTokenPower2()
{
	return tokenPower2;
}



