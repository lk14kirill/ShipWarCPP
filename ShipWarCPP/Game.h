#pragma once
#include <vector>
#include "Values.h"
class Player;
struct Point;
struct Ship;

using namespace std;
class Game
{
public:
	void Play(Player* player1,Player* player2);
	Game();
	~Game();
private: 
	vector<vector<char>> drawableField;
	bool isGameEnded = false;
	Player* player1;
	Player* player2;
	int numberOfPlayerToMove = 0;

	void Cycle();
	void DrawFields();
	void DefineNextPlayerToMove(int numberPlayerThatMoved , bool hit);
	void CheckForWinner(Player* player,Player* playerToWin);
	void MakeAMove(Player* attacking, Player* defending,int playerNumber);
	void ChangeShipsVisibilityIfHumans(Player* attacking, Player* defending);
	Point Attack(Player* player,Player* defending);
	Point GenerateAttackPoint(Player* player,vector<Ship> enemyShips);
	bool ifShipAlreadyShot(vector<Ship>ships,Point pointToCheck);
	bool ifContainsPoint(Player* player,Point point);
	bool CheckHit(Player* playerToHit, Point point);
};

