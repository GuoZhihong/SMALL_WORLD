#ifndef Tokens_h

#define Tokens_h
#include <string>
using namespace std;

class Tokens
{
private:
	int UsingRaceToken;
	int UnusedRaceToken;
	int coins;

public:
	Tokens();
	~Tokens();

	void display();
	void SetUsingRaceToken(int UsingRaceToken);
	int GetUsingRaceToken();

	void SetUnusedRaceToken(int UnusedRaceToken);
	int GetUnusedRaceToken();

	void Setcoins(int coins);
	int Getcoins();

};

#endif  Tokens_h
#pragma once
