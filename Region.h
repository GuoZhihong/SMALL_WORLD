#pragma once
#include<list>
#include<vector>
#include <iostream>
#include <string>
using namespace std;

class Region
{
public:
	Region(void);
	Region(int nodeNumber,int x,int y, vector<int> adjacentNodes,string regionTpye,vector<string>specialRegion);
	~Region(void);
	int getNodeNumber();
	int getX();
	int getY();
	vector<int> getAdjacentNodes();
	string getRegionTpye();
	vector<string> getSpecialRegion();
	void display();
	void setplayerNumber(int i);
	int getplayerNumber();

	void setTokenNeeded(int i);
	int getTokenNeeded();

	void setCurrentOcupiedToken(int i);
	int  getCurrentOcupiedToken();

	void setOcupiedRace(string s);
	string getOcupiedRace();
	int playerNumber;

private:
	int nodeNumber;
	int x;
	int y;
	int tokenNeeded;
	int currentOcupiedToken;
	string ocupiedRace;

	vector<int> adjacentNodes;
	string regionTpye;
	vector<string>specialRegion;
};