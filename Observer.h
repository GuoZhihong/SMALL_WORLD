#ifndef Observer_h
#define Observer_h
#include"Subject.h"
#include<iostream>

using namespace std;
class Subject;
class Observer
{
public:
	Observer(Subject * subject);
	Observer();
	~Observer();
	virtual void update(int y) = 0;
	Subject *getSubject();
	void setSubject(Subject * subject);
private:
	Subject * subject;
	int method;
};
#endif // !1


