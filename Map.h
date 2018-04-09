#ifndef MAP_H
#define MAP_H
#include <sstream>
#include <iostream>
#include<list>
#include<vector>
#include<stdlib.h> 
#include"Region.h"
#include"MapLoader.h"
#include"Subject.h"
using namespace std;
class Map:public Subject
{
public:
	Map(int M,int N,int playerNumber);
	Map(void);
	~Map(void);
	void drawMap(void);
	void setAdjacentNodes(int node,vector<int> adjacentNodes);
	bool isAdacentNode(int a,int b);
	void setupRegions(void);
	void setupMatrix();
	vector<Region> getRegionList();
	Region getRegion(int nodeNumber);
	void setRegionList(vector<Region> regionList);
	void displayRegionList(void);
	vector<char> getEdgeRegions();
	vector<Region> regionList;
private:
	int M, N;
	vector<vector<char> > coordinates;
	vector<vector<int> > adjacentMatrix;	
	vector<char> edgeRegions;
};
#endif MAP_H