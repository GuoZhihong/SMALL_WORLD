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

	string M, N; int m, n;
	
	while (inStream.peek() !='\n')
	{
		getline(inStream, M, '=');
		inStream >> m;
		inStream.get();

		getline(inStream, N, '=');
		inStream >> n;
		inStream.get();
	}
	cout << "The map size is " << m << " * " << n << endl;
	cout << endl;
	getline(inStream, null, '\n');
	getline(inStream, null, '\n');


	int node, x, y;
	
	while (!inStream.eof()) {
		list<int> adjacentNodes;

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
		cout <<"Coordinates are x = "<< x <<" y ="<< y<<endl;

		
		int token; 
		while (inStream.peek() != '\n'&&!(inStream.eof()))
		{	
			inStream >> token;
			inStream.get();
			adjacentNodes.push_back(token);

		}
		cout <<"Here are connected point with node "<<node<<endl;
		list<int>::iterator itera;
		for (itera = adjacentNodes.begin(); itera != adjacentNodes.end(); itera++) {
			if (*itera == node) {
				cout << "cannot have a node is connected to its own,invalid map file" << endl;
				system("pause");
				exit(0);
			}
			cout << *itera <<endl;
		}
		if (adjacentNodes.size() == 0) {
			cout << "cannot have a node is connected with nothing,invalid map file" << endl;
			system("pause");
			exit(0);
		}
		cout << endl;
	}
	cout << "The map file has been loaded successfully" << endl;
	
}

