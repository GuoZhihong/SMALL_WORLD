#ifndef VictoryCoinsObserverDecorator_h
#define VictoryCoinsObserverDecorator_h
#include"Observer.h"
#include"Player.h"
class VictoryCoinsObserverDecorator:public Observer
{
public:
	VictoryCoinsObserverDecorator(Subject * subject) : Observer(subject) {};
	~VictoryCoinsObserverDecorator() {};
	void update(int coins);
	int playerIndex = 0;
	void setPlayerIndex(int x);
};

#endif VictoryCoinsObserverDecorator_h
