#ifndef Race_h
#define Race_h
#include <string>
using namespace std;

class Race
{
private:
	string RaceName = "Null";
	int RaceTokens;
	int Number;
	int Select_Coin=0;

	string coinPower="Null";
	string tokenPower="Null";
	int specialTokenNumber=0;

public:
	Race();
	Race(int num);
	~Race();

	void display();
	 
	string GetRaceName();
	void setSpecialTokenNumber(int i);
	int getSpecialTokenNumber();
	
	void SetSelect_Coin(int i);

	int GetRaceTokens();

	int GetSelect_Coin();

	void setCoinPower(string power);
	string getCoinPower();

	void setTokenPower(string tpower);
	string getTokenPower();

};

#endif  Race_h
