#ifndef PlayerDominationObserverDecorator_h
#define PlayerDominationObserverDecorator_h
#include"Observer.h"
#include"Player.h"

class PlayerDominationObserverDecorator:public Observer
{
public:
	PlayerDominationObserverDecorator(Subject * subject) :Observer(subject) {};
	~PlayerDominationObserverDecorator() {};
	void update(int y);
	int method = 0;
	void setMethod(int x);
	int getMethod();
	int currentPlayerIndex = 0;
	int oponentPlayerIndex = 0;
};

#endif PlayerDominationObserverDecorator// !FooterPhaseObserver
