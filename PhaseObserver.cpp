#include "PhaseObserver.h"

void PhaseObserver::update(int playerIndex)
{
	switch (location)
	{
	case 1:
		cout << "---------------This is Part1:Phase Observer----------------" << endl;
		switch (method) {
		case 1:
			cout << "Player " << playerIndex << ": Pick a race and badge" << endl;
			break;
		case 2:
			cout << "Player " << playerIndex << ": Conquers some regions" << endl;
			break;
		case 3:
			cout << "Player " << playerIndex << ": Scores some victory coins" << endl;
			break;
		default:
			exit(0);
		}
		break;
	case 2:
		cout << "---------------This is Part1:Phase Observer----------------" << endl;

		switch (method) {
		case 1:
			cout << "Player " << playerIndex << ": Picked a race and badge" << endl;
			break;
		case 2:
			cout << "Player " << playerIndex << " finished his Conquere round" << endl;
			break;
		case 3:
			cout << "Player " << playerIndex << ": Scored some victory coins" << endl;
			break;
		default:
			exit(0);
		}
		break;
	default:
		break;
	}

}
