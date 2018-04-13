#include <iostream>
#include "Subject.h"

void Subject::attach(Observer * o)
{
	_observers.push_back(o);
}

void Subject::Detach(int x)
{
	switch (x)
	{
	case 1:
		cout<<"You have removed Player Domination Observer "<<endl;
		break;
	case 2:
		cout << "You have removed Player Hands Observer " << endl;
		break;
	case 3:
		cout << "You have removed Victory Coins Observer " << endl;
		break;
	default:
		break;
	}
}

void Subject::notify()
{
	for (int i = 0; i < _observers.size(); i++)
	{
		_observers[i]->update(0);
	}
}
