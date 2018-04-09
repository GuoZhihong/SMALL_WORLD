#ifndef Dice_h
#define Dice_h
#include <cstdlib>
#include <ctime>
class Dice
{
private:
	int LastRoll;


public:
	Dice();
	~Dice();

	void Roll();
	int GetNumber();
	void Display();
	void Reset();


};




#endif  Dice_h
