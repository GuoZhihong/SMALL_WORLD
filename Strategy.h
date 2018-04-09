#ifndef Strategy_h
#define Strategy_h
#include"Player.h"
class Player;
class Strategy{ 
public:
	virtual void execute(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[]) = 0;
};
#endif  Strategy_h