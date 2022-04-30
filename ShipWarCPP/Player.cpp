#include "Player.h"
Player::Player(int shipsQuantity, PlayerType type,bool areShipsHidden)
{
	ships = ShipGeneration::GenerateShips(shipsQuantity);
	this->type = type;
	this->name = name;
	this->shipsQuantity = shipsQuantity;
	this->areShipsHidden = areShipsHidden;
	if (type == PlayerType::ai)
		name = "Bot";
	else
		name = "Human";
}
Player::~Player()
{
	ships.clear();
	ships.shrink_to_fit();
	missesOnThisPlayerField.clear();
	missesOnThisPlayerField.shrink_to_fit();
}