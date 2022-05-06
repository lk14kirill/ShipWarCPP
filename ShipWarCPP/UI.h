#pragma once
#include "Values.h"
#include <string>

struct Point;

using namespace std;

class UI
{
public:
	static PlayerType AskForPlayerType();
	static Point AskForAttack();
	static int AskForShipQuantity();
	static bool AskForGame();
	static bool AskForUpdatingPlayers();
	static void Greetings();
	static void ShowResult(Player* player1,Player* player2,int gamesCount);
	static void DeclareAWinner(string name);
	static void WriteColoredSentence(string sentence, int color);
	static void WriteInfoAboutMove(Point hitPoint, string name, bool hit);
private:
	static bool IsInRange(string symbols);
};

