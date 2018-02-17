#include"Map.h"
#include"MapLoader.h"
#include "Badges.h"
#include "pieces.h"
#include "Race.h"
#include "Tokens.h"
#include <iostream>
#include "Dice.h"
#include "Player.h"

using namespace std;

int main() {
	cout << "===================================Part1:Map========================================" << endl;
	cout << "Please input the size of map" << endl;
	int M, N;
	cin >> M;
	cin >> N;
	Map map = Map(M, N);
	map.drawMap(0, 0, 0);

	map.setNode(1, 1, 1, { 2,3,4 });
	map.setNode(2, M, N, { 1,3 });
	map.setNode(3, 1, N, { 1,2,4 });
	map.setNode(4, M, 1, { 1,3 });

	map.setNode(500, M + 1, N + 1, { 1,3 });
	map.isAdacentNode(1, 2);
	map.isAdacentNode(2, 3);
	map.isAdacentNode(2, 4);
	cout << endl;
	cout << "===================================Part2:MapLoader========================================" << endl;
	string fileName;
	cout << "Please input the map file name:" << endl;
	cin >> fileName;
	MapLoader mapLoader;
	mapLoader.openInput(fileName);
	mapLoader.readFile();
	mapLoader.closeInput();
	cout << "===================================Part3:Dice========================================" << endl;
//Part3:Dice----------------------------------------------------------------
	
// seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	Dice MyDice;
	MyDice.Display();

	for (int i = 0; i < 10; i++)
	{
		MyDice.Roll();
		MyDice.Display();
	}

	MyDice.Reset();
	MyDice.Display();

	cout << endl;
	cout << "===================================Part4:Player========================================" << endl;
//Part4:Player-----------------------------------------------------------------
	Player player_1;
	player_1.display();
	player_1.pick_race();
	player_1.conquers();
	player_1.scores();


	cout << endl;
	cout << "=============Part 5: Tokens/ Fantasy Race Banners/ Badges/ pieces=============================================" << endl;
//Part 5: Tokens/ Fantasy Race Banners/ Badges/ pieces---------------------------------------------


	Race race(5);
	race.display();
	cout << endl;

	Badges badges(3);
	badges.display();
	cout << endl;
	
	pieces p(6);
	p.display();
	cout << endl;

	Tokens tokens;
	tokens.display();
	cout << endl;

	system("pause");
	return 0;
}



