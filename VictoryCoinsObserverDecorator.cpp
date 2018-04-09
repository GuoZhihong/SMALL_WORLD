#include "VictoryCoinsObserverDecorator.h"

void VictoryCoinsObserverDecorator::update(int coins)
{
	cout << "---------------This is Part4:Victory Coins Observer Decorator----------------" << endl;
	cout <<"Player " << playerIndex <<"  scores " <<coins<<" for this round."<< endl;
}

void VictoryCoinsObserverDecorator::setPlayerIndex(int x)
{
	this->playerIndex = x;
}
