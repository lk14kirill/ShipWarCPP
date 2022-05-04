#include "ShipGeneration.h"
#include "Values.h"
#include "Ship.h" 
#include "Point.h"

vector<Ship> ShipGeneration::GenerateShips(int quantity)
{
	vector<Ship> ships(quantity);
	for (int i = 0; i < quantity; i++) 
	{
		Point newCoords;
		do
		{
			newCoords = GeneratePoint(Values::width, Values::height);
			ships[i] = Ship(newCoords,ShipState::alive);
		} 
		while (ifCanSpawnShip(ships, newCoords));
	}
	return ships;
}
bool ShipGeneration::ifCanSpawnShip(vector<Ship>ships,Point newPoint)
{
	for(Ship ship:ships)
	{
		if (ship.coords == newPoint)return false;
	}
	return true;
}
Point ShipGeneration::GeneratePoint(int width, int height)
{
	int x = rand() % (width-1)+1;
	int y = rand() % (height-1)+1;
	return Point(x, y);
}
