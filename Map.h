#include <iostream>
#include<list>
#include<vector>
#include<stdlib.h> 
using namespace std;

class Map
{
public:
	Map(int M,int N);
	~Map(void);
	void drawMap(int node,int x,int y);
	void setAdjacentNodes(int node,list<int> adjacentNodes);
	bool isAdacentNode(int a,int b);
	void setNode(int node,int x,int y,list<int>adjacentNodes);
	void setupMatrix(void);
private:
	int M, N;
	char **coordinates;
	int  **adjacentMatrix;
};