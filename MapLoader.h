#ifndef MAPLOADER_H
#define MAPLOADER_H
#include<iostream>
#include <fstream>
#include<string>
#include<list>
#include"Map.h"
#include"Region.h"
using namespace std;

class MapLoader
{
public:
	MapLoader(void);
	~MapLoader(void);
	void openInput(string path);
	void closeInput();
	void readFile();
	int getM();
	int getN();
	vector<Region> getRegions();
private:
	ifstream inStream;
	ofstream outStream;
	vector<Region> nodeSets;
	int m, n;
};

#endif MAPLOADER_H
