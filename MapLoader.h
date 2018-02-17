#include<iostream>
#include <fstream>
#include<string>
#include<list>
using namespace std;

class MapLoader
{
public:
	MapLoader(void);
	~MapLoader(void);
	void openInput(string path);
	void closeInput();
	void readFile();

private:
	ifstream inStream;
	ofstream outStream;
};
