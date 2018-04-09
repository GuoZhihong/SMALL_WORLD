#include "PlayerDominationObserverDecorator.h"

void PlayerDominationObserverDecorator::update(int y)
{
	cout << "---------------This is Part4:Player Domination Observer Decorator----------------" << endl;
	if (method == 1) {
		cout << "Player " << currentPlayerIndex << " just conquered region " << (char)(y + 64) << endl;
	}
	else if (method == 2) {
		cout << "Player " << currentPlayerIndex << " just conquered region " << (char)(y + 64) << endl;
		cout<<"This region was belong to player " <<oponentPlayerIndex <<endl;
	}
}

void PlayerDominationObserverDecorator::setMethod(int x)
{
	this->method = x;
}

int PlayerDominationObserverDecorator::getMethod()
{
	return method;
}
