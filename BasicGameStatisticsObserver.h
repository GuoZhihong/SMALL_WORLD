#ifndef BasicGameStatisticsObserver_h
#define BasicGameStatisticsObserver_h
#include"Subject.h"
#include<iostream>
#include"GameStatisticsObserver.h"
class BasicGameStatisticsObserver :public Observer
{
public:
	BasicGameStatisticsObserver(Subject * subject) :Observer(subject){};
	~BasicGameStatisticsObserver(){};
	void update(int roundNumber);
};
#endif BasicGameStatisticsObserver
