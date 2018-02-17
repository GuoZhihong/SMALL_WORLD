#include <iostream>	
#include <string>
#include "pieces.h"
using namespace std;



	string pieces::GetPieceName() {
		return PieceName;
	}

	void pieces::display()
	{
		cout << "The PieceName is : "  << PieceName << endl;
	}


	pieces::pieces(int num)
{
	switch (num)
	{
	case 1:
		PieceName = " Troll Lairs";
		break;
	case 2:
		PieceName = "Fortresses";
		break;
	case 3:
		PieceName = "Mountains";
		break;
	case 4:
		PieceName = "Encampments";
	case 5:
		PieceName = "Holes-inthe-Ground";
		break;
	case 6:
		PieceName = "Heroes";
		break;
	case 7:
		PieceName = "Dragon";
		break;
	
	default:
		PieceName = "";
	}
}

	pieces::~pieces()
{
}




