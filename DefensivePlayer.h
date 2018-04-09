#ifndef DefensivePlayer_h
#define DefensivePlayer_h
#include"Strategy.h"
#include"Player.h"
class DefensivePlayer :public Strategy, Player
{
public:
	void execute(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[]);
	void conquers(Map& map, int roundNumber, vector<Player>& playerList, int currentPlayer);
	void redistribution1(Map& map, vector<Player>& playerList, int currentPlayer);
	void redistribution2(Map& map, vector<Player>& playerList, int currentPlayer);
};
#endif  DefensivePlayer_h