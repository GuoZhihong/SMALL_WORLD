#include <iostream>
#include "Observer.h"


Observer::Observer(Subject * subject)
{
	this->subject = subject;
	subject->attach(this);
}

Observer::Observer()
{
}

Observer::~Observer()
{
}

Subject * Observer::getSubject()
{
	return subject;
}

void Observer::setSubject(Subject * subject)
{
	this->subject = subject;
	subject->attach(this);
}
