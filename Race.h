#ifndef Race_h

#define Race_h
#include <string>
using namespace std;

class Race
{
private:
	string RaceName;
	int RaceTokens;
	int Number;

public:
	Race(int num);
	~Race();

	void display();
	 
	string GetRaceName();

	int GetRaceTokens();

};

#endif  Race_h
#pragma once
