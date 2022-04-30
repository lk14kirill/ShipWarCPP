#pragma once
#include <vector>
#include <string>
#include "Values.h"
#include "Ship.h"
#include "ShipGeneration.h"
#include "Values.h"
using namespace std;
class Player
{
public:
	Player(int shipsQuantity, PlayerType type, string name);
	~Player();
	vector<Point> missesOnThisPlayerField;
	vector<Ship> ships;
 
	PlayerType GetType() { return type; }
	bool AreShipsHidden() { return areShipsHidden; }
	string GetName() { return name; }
private:
	PlayerType type;
	string name;
	bool areShipsHidden = false;
};


