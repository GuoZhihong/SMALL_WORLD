#include "Map.h"
Map::Map(int M,int N)
{
	this->M = M;
	this->N = N;
	setupMatrix();
}

Map::~Map(void)
{
	delete[]adjacentMatrix;
	delete[]coordinates;
}

void Map::drawMap(int node,int x,int y)
{
	system("Cls");
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
			else if (i == y  && j == x && x !=0 && y !=0) {//print current added node
				coordinates[i][j] = '@';
				cout << coordinates[i][j];
			}
			else if (coordinates[i][j] == '@') {//print exsited nodes
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

void Map::setAdjacentNodes(int node,list<int> x)
{
	list<int>::iterator itera;
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

void Map::setNode(int node, int x, int y, list<int>adjacentNodes)
{
	if (node > M*N || (x == 0 && y == 0)) {
		cout << "Invalid node "<<node<<" ,out of map range,so do nothing." << endl;
		return;
	}
	setAdjacentNodes(node, adjacentNodes);
	drawMap(node,x,y);
}

/*2-D array initialisazion*/
void Map::setupMatrix(void)
{	/*
		edges
	__________
	| _______ |
	||       ||
	||  map  ||
	||_______||
	|_________|


	*/
	coordinates = new char*[M+2];//reserve 2 rows,and 2 columns for map edges, operatable map size is m*n 
	for (int i = 0; i < (N+2); i++) {
		coordinates[i] = new char[N+2];
		for (int j = 0; j < (N+2); j++) {
			coordinates[i][j] = ' ';
		}
	}

	adjacentMatrix = new int*[(M*N) + 1];
	for (int i = 0; i < (M*N + 1); i++) {
		adjacentMatrix[i] = new int[(M*N) + 1];
		for (int j = 0; j < (N*M + 1); j++) {
			adjacentMatrix[i][j] = 0;
		}
	}
}
