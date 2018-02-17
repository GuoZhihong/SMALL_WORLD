#pragma once
#include <iostream>

#include "Dice.h"
using namespace std;




Dice::Dice() : LastRoll(0)
{
	cout << "Dice Object is being created." << endl;
}

Dice::~Dice()
{
	cout << "Dice Object is being deleted." << endl;
}

void Dice::Roll()
{
	LastRoll = 0;

	// generate a random number between 0 and 3 (0 value has 50% chance coming out)
	int temp = 0;
	temp = (rand() % 2);
	if (temp == 0) {
		LastRoll = 0;
	}
	else
	{
		LastRoll = (rand() % 3 + 1);
	}
}

void Dice::Display()
{
	cout << "The last roll was " << LastRoll << "." << endl;

}

int Dice::GetNumber()
{
	return LastRoll;

}
void Dice::Reset()
{
	LastRoll = 0;
}


