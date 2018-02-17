#ifndef Player_h
#define Player_h
#include <string>	
#include "Dice.h"
using namespace std;

class Player
{
public:
	Player();
	~Player();

	void pick_race();
	void conquers();
	void scores();

	void display();

private:
	int Regions_Unused;
	int Regions_Inhand;

	int Tokens_Unused;
	int Tokens_Inhand;

	string Race_Unused;
	string Race_Inhand;

	string Badges_Unused;
	string Badges_Inhand;

	int Coins_Unused;
	int Coins_Inhand;

	int Dice_Number_Unused;
	int Dice_Number_Inhand;


};



















#endif Player_h
#pragma once
