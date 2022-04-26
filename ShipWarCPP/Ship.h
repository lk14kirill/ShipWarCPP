#pragma once
#include "Values.h"
#include "Point.h"
struct Ship
{
public:
	Point coords;
	ShipState state;

	Ship(Point point,ShipState state)
	{
		coords = point;
		this->state = state;
	}
	Ship()
	{
	}
	~Ship()
	{
	}
};

