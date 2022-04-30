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
    
	int GetShipsQuantity() { return shipsQuantity; }
	bool AreShipsHidden() { return areShipsHidden; }
	PlayerType GetType() { return type; }
	string GetName() { return name; }
private:
	PlayerType type;
	string name;
	bool areShipsHidden = false;
	int shipsQuantity;
};


