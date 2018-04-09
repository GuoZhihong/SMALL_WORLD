#ifndef GameStatisticsObserver_h
#define GameStatisticsObserver_h
#include"Observer.h"
#include"Map.h"

class GameStatisticsObserver:public Observer
{
public:
	GameStatisticsObserver(Subject * subject):Observer(subject) {};
	~GameStatisticsObserver() {};
	void update(int y);
};
#endif  GameStatisticsObserver_h