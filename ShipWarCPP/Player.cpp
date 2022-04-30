#include "Player.h"
Player::Player(int shipsQuantity, PlayerType type, string name)
{
	ships = ShipGeneration::GenerateShips(shipsQuantity);
	this->type = type;
	this->name = name;
	this->shipsQuantity = shipsQuantity;
	if (type == PlayerType::ai)
		areShipsHidden = true;
}
Player::~Player()
{
	ships.clear();
	ships.shrink_to_fit();
	missesOnThisPlayerField.clear();
	missesOnThisPlayerField.shrink_to_fit();
}