#ifndef PhaseObserver_h
#define PhaseObserver_h
#include"Subject.h"
#include<iostream>
class PhaseObserver: public Observer
{
public:
	PhaseObserver(Subject * subject, int method) :Observer(subject) { this->method = method; };
	~PhaseObserver() {};
	void update(int playerIndex);
	int method = 0;
	int location = 0;
};
#endif PhaseObserver// !1
