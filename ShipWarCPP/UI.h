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
	static void Greetings();
	static void DeclareAWinner(string name);
	static bool AskForGame();
	static int AskForShipQuantity();
	static Point AskForAttack();
	static void WriteInfoAboutMove(Point hitPoint, string name, bool hit);
	static void WriteColoredSentence(string sentence, int color);
private:
	static bool IsInRange(string symbols);
};

