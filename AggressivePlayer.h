#ifndef AggressivePlayer_h
#define AggressivePlayer_h
#include"Strategy.h"
#include"Player.h"
class AggressivePlayer:public Strategy,Player
{
public:
	//AggressivePlayer();
	//~AggressivePlayer();
	void execute(vector<Player>& playerList,Map& map,int currentPlayer,int roundNumber, Race race[], Badges badges[]);
	void pick_race(Race race[], Badges badges[], vector<Player>& playerList, int currentPlayer);
	void conquers(Map& map, int roundNumber, vector<Player>& playerList, int currentPlayer);
	void redistribution(Map& map, vector<Player>& playerList, int currentPlayer);
};
#endif  AggressivePlayer_h