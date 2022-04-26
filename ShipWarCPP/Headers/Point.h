#pragma once
struct Point
{
public:
	Point(int x, int y):x(x),y(y){}
	Point():x(0),y(0){}
	int x;
	int y;
	bool operator==(const Point& r)
	{
		if (x == r.x && y == r.y)return true;
		return false;
	}

};

