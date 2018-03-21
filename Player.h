#ifndef Player_h
#define Player_h
#include <string>	
#include<vector>
#include "Dice.h"
#include "Region.h"
#include"Race.h"
#include"Badges.h"
#include "Map.h"
#include <algorithm>
using namespace std;

class Player
{
public:
	Player();
	Player(int playerIndex);
	~Player();

	void pick_race(Race race[], Badges badges[]);
	void conquers(Map& map, int roundNumber, vector<Player> playerList);
	void scores();
	void display();

	void setRace_Unused(Race r);
	Race getRace_Unused();

	void setRace_Inhand(Race r);
	Race getRace_Inhand();

	void setBadges_Unused(Badges b);
	Badges getBadges_Unused();

	void setBadges_Inhand(Badges b);
	Badges getBadges_Inhand();

	void setCoins_Inhand(int i);
	int getCoins_Inhand();

	void setCoins_Unused(int i);
	int getCoins_Unused();

	void setTotalScore(int i);
	int getTotalScore();
	
	void setTokens_Inhand(int i);
	int getTokens_Inhand();

	void setTokens_Unused(int i);
	int getTokens_Unused();

	void setPlayerIndex(int i);
	int getPlayerIndex();

	bool enableToPickRegion(Region region,int RoundNumber,Map map);

	vector<Region> getRegions_Unused();
	vector<Region> getRegions_Inhand();
	void setRegions_Unused(vector<Region> regionList);
	void setRegions_Inhand(Region region);
	void setUnusedRaceName(string s);
	string getUnusedRaceName();

	void setSpecialPowerToken(int i);
	int getSpecialPowerToken();

	void setDice(Dice d);
	Dice getdice();

	void setDice_Number_Inhand(int i);
	int getDice_Number_Inhand();
	bool notAdjacentRegion(int regionIndex);
	bool notOnTheEdges(char regionNumber,Map map);
	bool belongItself(int regionIndex);
	bool isWaterRegion(int regionIndex,Map& map);
	bool notValidInput(int regionIndex, Map map);
	void conquereOthers(int regionIndex,Map& map,vector<Player>playerList);
private:
	vector<Region> Regions_Unused;
	vector<Region> Regions_Inhand;

	int Tokens_Unused;
	int Tokens_Inhand;

	Race Race_Unused;
	Race Race_Inhand;

	Badges Badges_Unused;
	Badges Badges_Inhand;

	int Coins_Unused;
	int Coins_Inhand;

	int Dice_Number_Unused;
	int Dice_Number_Inhand;

	Dice dice;

	string unusedRaceName;

	int specialPowerToken;
	int totalScore;
	int test;
	int playerIndex;

};



















#endif Player_h
#pragma once
