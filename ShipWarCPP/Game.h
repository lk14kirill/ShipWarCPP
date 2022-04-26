#pragma once
#include <vector>
#include "Values.h"
#include "Player.h"
#include "Drawer.h"
#include "FieldGeneration.h"
#include "UI.h"
using namespace std;
class Game
{
public:
	void Play(Player* player1,Player* player2,UI*ui);
	Game()
	{
		drawableField = fieldgenerator->GenerateField(Values::width, Values::height);
	}
	~Game()
	{
		delete drawer;
		delete fieldgenerator;
		delete player1;
		delete player2;
		delete ui;

		drawableField.clear();
		drawableField.shrink_to_fit();
	}

private: 
	vector<vector<char>> drawableField;
	Drawer * drawer = new Drawer();
	FieldGeneration* fieldgenerator = new FieldGeneration();
	bool isGameEnded = false;
	Player* player1;
	Player* player2;
	PlayerTurn turn;
	UI* ui;

	void Update();
	void DrawFields();
	void DefineNextPlayerToMove(int numberPlayerThatMoved , bool hit);
	void CheckForWinner(Player* player,Player* playerToWin);
	void MakeAMove(Player* attacking, Player* defending,int playerNumber);
	Point Attack(Player* player,Player* defending);
	Point GenerateAttackPoint(Player* player,vector<Ship> enemyShips);
	bool ifShipAlreadyShot(vector<Ship>ships,Point pointToCheck);
	bool ifContainsPoint(Player* player,Point point);
	bool CheckHit(Player* playerToHit, Point point);
};

