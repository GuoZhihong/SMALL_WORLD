#include <iostream>
#include "Player.h"

using namespace std;


Player::Player()
{
	

}

Player::~Player()
{
}

void Player::display()
{
	cout << "The Regions_Unused is : " << Regions_Unused << endl;
	cout << "The Regions_Inhand is : " << Regions_Inhand << endl;
	cout << "The Tokens_Unused is : " << Tokens_Unused << endl;
	cout << "The Tokens_Inhand is : " << Tokens_Inhand << endl;
	cout << "The Race_Unused is : " << Race_Unused << endl;
	cout << "The Race_Inhand is : " << Race_Inhand << endl;
	cout << "The Badges_Unused is : " << Badges_Unused << endl;
	cout << "The Badges_Inhand is : " << Badges_Inhand << endl;
	cout << "The Coins_Unused is : " << Coins_Unused << endl;
	cout << "The Coins_Inhand is : " << Coins_Inhand << endl;

}

void Player::pick_race() 
{
	cout << "Pick_race() is running. Waitting  for assignment_2  to complete ." << endl;

}
void Player::conquers() 
{
	cout << "Conquers() is running. Waitting  for assignment_2  to complete ." << endl;
}


void Player::scores() 
{
	cout << "Scores() is running. Waitting  for assignment_2  to complete ." << endl;

}