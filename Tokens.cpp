#include <iostream>
#include <string>
#include "Tokens.h"
using namespace std;



Tokens::Tokens() {
	UsingRaceToken = 0;
	UnusedRaceToken = 0;
	coins = 0;
}

Tokens::~Tokens()
{}

void Tokens::display()
{
	cout << "The UsingRaceToken is :" << UsingRaceToken << endl;
	cout << "The  UnusedRaceToken is :" << UnusedRaceToken << endl;
	cout << "The  coins is :" << coins << endl;
}

void Tokens::SetUsingRaceToken(int UsingRaceToken)
{
	UsingRaceToken = UsingRaceToken;
}

int  Tokens::GetUsingRaceToken()
{
	return UsingRaceToken;
}

void Tokens::SetUnusedRaceToken(int UnusedRaceToken)
{
	UnusedRaceToken = UnusedRaceToken;
}

int  Tokens::GetUnusedRaceToken()
{
	return UnusedRaceToken;
}

void Tokens::Setcoins(int coins)
{
	coins = coins;
}

int  Tokens::Getcoins()
{
	return coins;
}


