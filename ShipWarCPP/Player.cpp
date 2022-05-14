#include "Player.h"
#include "ShipGeneration.h"
#include "Ship.h"

int Player::GetShipsQuantity() { return shipsQuantity; }
int Player::GetWins() { return wins; }
bool Player::AreShipsHidden() { return areShipsHidden; }
PlayerType Player::GetType() { return type; }
string Player::GetName() { return name; }
void Player::SetShipsVisibility(bool areHidden) { areShipsHidden = areHidden; }
void Player::AddWin() { wins += 1; }

void Player::UpdateValues(int shipsQuantity)
{
	ships = ShipGeneration::GenerateShips(shipsQuantity);
	this->shipsQuantity = shipsQuantity;
	missesOnThisPlayerField.clear();
}
Player::Player(string name,int shipsQuantity, PlayerType type,bool areShipsHidden)
{
	ships = ShipGeneration::GenerateShips(shipsQuantity);
	this->type = type;
	this->name = name;
	this->shipsQuantity = shipsQuantity;
	this->areShipsHidden = areShipsHidden;
	if (type == PlayerType::ai)
		name = "Bot";
}
Player::~Player()
{
	ships.clear();
	ships.shrink_to_fit();
	missesOnThisPlayerField.clear();
	missesOnThisPlayerField.shrink_to_fit();
}
