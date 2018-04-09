#ifndef Subject_h
#define Subject_h
#include "Observer.h"
#include<vector>
using namespace std;
class Observer;
class Subject
{
public:
	Subject(){};
	~Subject(){};

	virtual void attach(Observer* o);
	virtual void Detach(int x);
	virtual void notify();
	vector<Observer *> _observers;
};
#endif Subject_h// !1


