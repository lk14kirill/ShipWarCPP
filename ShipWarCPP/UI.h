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
	static PlayerType AskForPlayerType();
	static Point AskForAttack();
	static int AskForShipQuantity();
	static bool AskForGame();
	static void Greetings();
	static void DeclareAWinner(string name);
	static void WriteColoredSentence(string sentence, int color);
	static void WriteInfoAboutMove(Point hitPoint, string name, bool hit);
private:
	static bool IsInRange(string symbols);
};

