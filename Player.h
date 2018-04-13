#ifndef Player_h
#define Player_h
#include <string>	
#include<vector>
#include "Dice.h"
#include "Region.h"
#include"Race.h"
#include"Badges.h"
#include "Map.h"
#include"Strategy.h"
#include <algorithm>
#include"PhaseObserver.h"
#include"PlayerDominationObserverDecorator.h"
#include"PlayerHandsObserverDecorator.h"
#include"VictoryCoinsObserverDecorator.h"
#include"BasicGameStatisticsObserver.h"
using namespace std;
class Strategy; class BasicGameStatisticsObserver;
class PlayerDominationObserverDecorator; class PlayerHandsObserverDecorator; class VictoryCoinsObserverDecorator;
class Player:public Subject
{
public:
	Player();
	Player(int playerIndex,Strategy* strategy);
	~Player();

	void pick_race(Race race[], Badges badges[]);
	void conquers(Map& map, int roundNumber, vector<Player>& playerList);
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
	void setRegions_Inhand(Region& region);
	void setRegions_Inhand(vector<Region> regionList);
	void setUnusedRaceName(string s);
	string getUnusedRaceName();

	/*special power method----------*/
	void setSpecialPowerToken(int i);
	int getSpecialPowerToken();
	void setCoinPower(string s);
	string getCoinPower();
	void setTokenPower(string s);
	string getTokenPower();

	void setDice_Number_Unused(int i);
	int getDice_Number_Unused();
	void setDice_Number_Inhand(int i);
	int getDice_Number_Inhand();
	bool notAdjacentRegion(int regionIndex);
	bool notOnTheEdges(char regionNumber,Map map);
	bool belongItself(int regionIndex);
	bool isWaterRegion(int regionIndex,Map& map);
	bool notValidInput(int regionIndex, Map map);
	void conquereOthers(int regionIndex,Map& map,vector<Player>& playerList);
	void redistribution(Map& map);
	void executeStrategy(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[]);
	vector<Region> Regions_Unused;
	vector<Region> Regions_Inhand;
	char getNeedDecorator();
	void setNeedDecorator(char needDecorator);
	bool getNeedPlayerDominationObserver();
	bool getNeedPlayerHandsObserver();
	bool getNeedVictoryCoinsObserver();
	void setNeedPlayerDominationObserver(bool choice);
	void setNeedPlayerHandsObserver(bool choice);
	void setNeedVictoryCoinsObserver(bool choice);

	PhaseObserver * phaseObserver;
	BasicGameStatisticsObserver * basicGameStatisticsObserver;
	PlayerDominationObserverDecorator * playerDominationObserverDecorator;
	PlayerHandsObserverDecorator * playerHandsObserverDecorator;
	VictoryCoinsObserverDecorator * victoryCoinsObserverDecorator;
	
	void notify(string x,int y);
private:

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

	string unusedRaceName;

	int specialPowerToken;
	string coinPower = "Null";
	string tokenPower = "Null";
	int gameTurnNumber = 0;


	int totalScore;
	int test;
	int playerIndex;
	char needDecorator;
	bool needPlayerDominationObserver;
	bool needPlayerHandsObserver;
	bool needVictoryCoinsObserver;


	Strategy *strategy;
};


#endif Player_h
