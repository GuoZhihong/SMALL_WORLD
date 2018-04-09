#ifndef ModeratePlayer_h
#define ModeratePlayer_h
#include"Strategy.h"
#include"Player.h"
class ModeratePlayer :public Strategy, Player
{
public:
	void execute(vector<Player>& playerList, Map& map, int currentPlayer, int roundNumber, Race race[], Badges badges[]);
	void conquers(Map& map, int roundNumber, vector<Player>& playerList, int currentPlayer);
	void redistribution(Map& map, vector<Player>& playerList, int currentPlayer);
};
#endif  ModeratePlayer_h