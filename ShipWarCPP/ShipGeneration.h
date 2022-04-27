#pragma once
#include <vector>
#include "Ship.h" 
#include "Values.h"
#include "Point.h"
using namespace std;
class ShipGeneration
{
public:
	static vector<Ship> GenerateShips(int quantity);
private:
	static bool ifCanSpawnShip(vector<Ship> ships,Point newCoords);
    static Point GeneratePoint(int width,int height);
};

