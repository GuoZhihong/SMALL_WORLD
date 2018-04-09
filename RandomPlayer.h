#ifndef RandomPlayer_h
#define RandomPlayer_h
#include"Strategy.h"
#include"Player.h"
class RandomPlayer :public Strategy, Player
{
public:
	void execute(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[]);
};
#endif  RandomPlayer_h