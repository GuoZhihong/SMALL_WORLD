#include "MapLoader.h"
MapLoader::MapLoader(void) {

}
MapLoader::~MapLoader(void) {
}
void MapLoader:: openInput(string path) {
	inStream.open(path);
	if (!inStream.good())
	{
		cout << "FILE OPENING ERROR - file path: " << path << endl;
		system("pause");
		exit(0);
	}
}

void MapLoader::closeInput()
{
	inStream.close();
}

void MapLoader::readFile()
{
	string null;
	getline(inStream, null, '\n');
	if (inStream.eof()) {
		cout << "Invalid map file,please specify the size of the map" << endl;
		system("pause");
		exit(0);
	}

	string M, N;
	
	while (inStream.peek() !='\n')
	{
		getline(inStream, M, '=');
		inStream >> m;
		inStream.get();

		getline(inStream, N, '=');
		inStream >> n;
		inStream.get();
	}
	//Map map = Map(m, n);
	getline(inStream, null, '\n');
	getline(inStream, null, '\n');
	cout << endl;
	cout << endl;

	int node, x, y;
	

	while (!inStream.eof()) {
		vector<int> adjacentNodes;
		vector<string>specialRegion;
		string regionType;
		inStream >> node;
		inStream.get();
		if (node > (m*n)) {
			cout << "Over the map size range,invalid map file" << endl;
			system("pause");
			exit(0);
		}

		inStream >> x;
		inStream.get();
		inStream >> y;
		inStream.get();

		int token; 
		while (inStream.peek() != '|')
		{	
			inStream >> token;
			inStream.get();
			if (token == node) {
				cout << "cannot have a node is connected to its own,invalid map file" << endl;
				system("pause");
				exit(0);
			}
			adjacentNodes.push_back(token);
		}
		inStream >> null;
		inStream.get();
		getline(inStream, regionType, ',');
		string token2;
		while (inStream.peek() != '\n' && !(inStream.eof())) {
			getline(inStream, token2, ',');
			specialRegion.push_back(token2);
		}
		
		Region region = Region(node, x, y,adjacentNodes,regionType,specialRegion);
		nodeSets.push_back(region);
		if (adjacentNodes.size() == 0) {
			cout << "cannot have a node is connected with nothing,invalid map file" << endl;
			system("pause");
			exit(0);
		}
	}
	cout << "The map has been loaded successfully" << endl;
}

int MapLoader::getM()
{
	return m;
}

int MapLoader::getN()
{
	return n;
}

vector<Region> MapLoader::getRegions()
{
	return nodeSets;
}

