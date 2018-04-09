#include "Map.h"
Map::Map(void){}
Map::Map(int M,int N,int playerNumber)
{	
	this->M = M;
	this->N = N;
	if (playerNumber == 2) {
		edgeRegions = {'B','C','D','H','I','L','W','V','T','R','Q','K','E','O'};
	}
	else if (playerNumber == 3) {

	}
	else if (playerNumber == 4) {

	}
	else {

	}
	setupMatrix();
}

Map::~Map(void)
{	
}

void Map::drawMap()
{	
	//system("cls");
	setupRegions();
	/*nested loop to display the edges of the map*/
	for (int i = 0; i < M+2; i++)
	{
		for (int j = 0; j < N+2; j++)
		{
			if ((i == 0 && j == 0) || (i == M+1 && j == 0) || (i == 0 && j == N+1 || (i == M+1 && j == N+1))) {
				coordinates[i][j] = '*';
				cout << coordinates[i][j];
			}
			else if (i == 0 && j != 0) {
				coordinates[i][j] = '*';
				cout << coordinates[i][j];
			}
			else if (j == 0 && i != 0) {
				coordinates[i][j] = '*';
				cout << coordinates[i][j];
			}
			else if (j == N+1 && i != M+1) {
				coordinates[i][j] = '*';
				cout << coordinates[i][j];
			}
			else if (i == M+1 && j != N+1) {
				coordinates[i][j] = '*';
				cout << coordinates[i][j];
			}
			else if (coordinates[i][j] >= 0|| coordinates[i][j]<=M*N) {//print exsited nodes
				cout << coordinates[i][j];
			}
			else {//null space in the map
				coordinates[i][j] = ' '; 
				cout << coordinates[i][j];
			}
		}
		cout << endl;
	}
}

void Map::setAdjacentNodes(int node,vector<int> x)
{
	vector<int>::iterator itera;
	for (itera = x.begin(); itera != x.end(); itera++)
	{
		adjacentMatrix[node][*itera] = 1;
		adjacentMatrix[*itera][node] = 1;
	}
}

bool Map::isAdacentNode(int a, int b)
{
	if (adjacentMatrix[a][b] == 1 && adjacentMatrix[b][a] == 1) {
		cout << "Node" <<a<<" is coonnected with Node"<<b<< endl;
		return true;
	}
	cout << "Node" << a << " is not coonnected with Node" << b << endl;
	return false;
}

void Map::setupRegions(void)
{
	int node, x, y; vector<int> adjacentNodes;
	for (int i = 0; i < (regionList.size()); i++)
	{
		node = regionList[i].getNodeNumber();
		x = regionList[i].getX();
		y = regionList[i].getY();
		adjacentNodes = regionList[i].getAdjacentNodes();

		if (node > M*N || (x == 0 && y == 0)) {
			cout << "Invalid node " << node << " ,out of map range,so do nothing." << endl;
			return;
		}
		if (node <= 26) {
			coordinates[y][x] = node + 64;//ASCII code
		}
		else {
			coordinates[y][x] = node + 70;
		}
		setAdjacentNodes(node, adjacentNodes);
	}
}

/*2-D array initialisazion*/
void Map::setupMatrix()
{	/*
		edges
	__________
	| _______ |
	||       ||
	||  map  ||
	||_______||
	|_________|


	*/

	/*
	coordinates.resize(M + N);
	
	*/

	coordinates.resize(M+N);//reserve 2 rows,and 2 columns for map edges, operatable map size is m*n 
	for (int i = 0; i < (M + N); i++) {
		coordinates[i].resize(N + 2);
		for (int j = 0; j < (N + 2); j++) {
			if (i < (M + 2)) {
				coordinates[i][j] = ' ';
			}
		}
	}
	
	adjacentMatrix.resize((M*N) + 1);
	for (int i = 0; i < (M*N+1); i++) {
		adjacentMatrix[i].resize((M*N)+1);
		for (int j = 0; j < (N*M+1); j++) {
			adjacentMatrix[i][j] = 0;
		}
	}
	
}

vector<Region> Map::getRegionList()
{
	return regionList;
}

Region Map::getRegion(int nodeNumber)
{
	return regionList[nodeNumber-1];
}

void Map::setRegionList(vector<Region> regionList)
{
	this->regionList = regionList;
}

void Map::displayRegionList(void)
{
	for (int i = 0; i < regionList.size(); i++)
	{
		regionList[i].display();
	}
	cout << endl;
	cout << endl;
}

vector<char> Map::getEdgeRegions()
{
	return edgeRegions;
}
