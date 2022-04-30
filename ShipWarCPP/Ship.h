#pragma once
#include "Values.h"
#include "Point.h"
struct Ship
{
public:
	Point coords;
	ShipState state;

	Ship(Point point,ShipState state): coords(point),state(state){}
	Ship() { Ship(Point(1, 1), ShipState::alive); };
};

