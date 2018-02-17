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

public:
	Badges(int num);
	~Badges();

	void display();
	
	string GetBadgeName();

	int GetBadgesTokens();	
};

#endif  Badges_h
#pragma once

