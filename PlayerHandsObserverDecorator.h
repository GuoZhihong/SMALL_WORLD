#ifndef PlayerHandsObserverDecorator_h
#define PlayerHandsObserverDecorator_h
#include"Observer.h"
class PlayerHandsObserverDecorator :public Observer
{
public:
	PlayerHandsObserverDecorator(Subject * subject) : Observer(subject) {};
	~PlayerHandsObserverDecorator() {};
	void update(int y);
};



#endif PlayerHandsObserverDecorator// !FooterPhaseObserver
