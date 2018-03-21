#ifndef pieces_h

#define pieces_h
#include <string>
using namespace std;

class pieces
{
private:
	string PieceName;

public:
	pieces(int num);
	~pieces();

	void display();

	string GetPieceName();

};

#endif  pieces_h
#pragma once