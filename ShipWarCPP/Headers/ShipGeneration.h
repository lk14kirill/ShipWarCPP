#pragma once
#include <vector>
#include "Ship.h" 
#include "Values.h"
#include "Point.h"
using namespace std;
class ShipGeneration
{
public:
	vector<Ship> GenerateShips(int quantity);
private:
	bool ifCanSpawnShip(vector<Ship> ships,Point newCoords);
    Point GeneratePoint(int width,int height);
};

