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
	Player(int shipsQuantity,PlayerType type,string name)
	{
		ships = shipGenerator->GenerateShips(shipsQuantity);
		this->type = type;
		this->name = name;
		if (type == PlayerType::ai)
			areShipsHidden = true;
	}
	~Player()
	{
		ships.clear();
		ships.shrink_to_fit();
		missesOnThisPlayerField.clear();
		missesOnThisPlayerField.shrink_to_fit();
		delete shipGenerator;
	}
	vector<Ship> ships;
	vector<Point> missesOnThisPlayerField;
	PlayerType type;
	bool areShipsHidden = false;
	string name;
private:
	ShipGeneration* shipGenerator = new ShipGeneration();
	


};

