#ifndef Badges_h

#define Badges_h
#include <string>
using namespace std;

class Badges
{
private:
	string BadgeName;
	int BadgesTokens;
	int Number;
	
	string coinPower;
	string tokenPower1;
	string tokenPower2;

public:
	Badges();
	Badges(int num);
	~Badges();

	void display();
	
	string GetBadgeName();

	int GetBadgesTokens();	

	void setCoinPower(string s);
	string getCoinPower();

	void setTokenPower1(string s);
	string getTokenPower1();

	void setTokenPower2(string s);
	string getTokenPower2();

};

#endif  Badges_h
#pragma once

