#include"Region.h"
Region::Region(void)
{
}

Region::Region(int nodeNumber, int x, int y, vector<int> adjacentNodes, string regionTpye, vector<string>specialRegion)
{
	this->nodeNumber = nodeNumber;
	this->x = x;
	this->y = y;
	this->regionTpye = regionTpye;
	this->playerNumber = 0;
	this->tokenNeeded = 2;
	this->ocupiedRace = "";
	this->currentOcupiedToken = 0;
	vector<int>::iterator itera;
	for (itera = adjacentNodes.begin(); itera != adjacentNodes.end(); itera++) {
		(this->adjacentNodes).push_back(*itera);
	}
	vector<string>::iterator itera2;
	for (itera2 = specialRegion.begin(); itera2 != specialRegion.end(); itera2++) {
		(this->specialRegion).push_back(*itera2);
	}
}

Region::~Region(void)
{ 
}

void Region::setplayerNumber(int i)
{
	this->playerNumber = i;
}
int Region::getplayerNumber()
{
	return playerNumber;
}

void Region::setTokenNeeded(int i)
{
	tokenNeeded = i;
}

int Region::getTokenNeeded()
{
	return tokenNeeded;
}

void Region::setCurrentOcupiedToken(int i)
{
	currentOcupiedToken = i;
}

int  Region::getCurrentOcupiedToken()
{
	return currentOcupiedToken;
}

void Region::setOcupiedRace(string s)
{
	ocupiedRace = s;
}

string Region::getOcupiedRace()
{
	if (ocupiedRace == "") {
		ocupiedRace = "N/A";
	}
	return ocupiedRace;
}

void Region::display()
{
	vector<int>::iterator itera;
	cout << "Region number: " << (char)(getNodeNumber() + 64) << ".  " << " Belongs: " << getplayerNumber() << " . " << " Region type: " << getRegionTpye() << " . " << "CurrentOcupiedToken: " << getCurrentOcupiedToken() << "  " << "TokenNeeded: " << getTokenNeeded() << "  " << "OcupiedRace: " << getOcupiedRace() << " . ";
	cout << " Adjacent regions : ";
	for (itera = adjacentNodes.begin(); itera != adjacentNodes.end(); itera++) {
		cout << (char)(*itera + 64)<<" ";
	}
	cout<<". ";
	if (specialRegion.size() != 0) {
		cout << "Special region type : ";
		for (int i = 0; i < specialRegion.size(); i++) {
			cout << specialRegion[i] << " ";
		}
	}
	cout << endl;
}

int Region::getNodeNumber()
{
	return nodeNumber;
}

int Region::getX()
{
	return x;
}

int Region::getY()
{
	return y;
}

vector<int> Region::getAdjacentNodes()
{
	return adjacentNodes;
}

string Region::getRegionTpye()
{
	return regionTpye;
}

vector <string> Region::getSpecialRegion()
{
	return specialRegion;
}
