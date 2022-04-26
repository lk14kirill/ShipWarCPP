#pragma once
#include <iostream>
#include <cctype>
#include <windows.h>
#include "Values.h"
#include "Point.h"
using namespace std;

class UI
{
public:
	void Greetings();
	void DeclareAWinner(string name);
	bool AskForGame();
	int AskForShipQuantity();
	Point AskForAttack();
	void WriteInfoAboutMove(Point hitPoint, string name, bool hit);
private:
	bool IsInRange(string symbols);
};

