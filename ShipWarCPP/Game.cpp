#include "Game.h"
#include "Player.h"
#include "Drawer.h"
#include "FieldGeneration.h"
#include "UI.h"
#include "Point.h"
#include "Ship.h"
#define byte char
#include <windows.h>
#include <iostream>

using namespace std;

Game::Game()
{
	drawableField = FieldGeneration::GenerateField(Values::width, Values::height);
}
Game::~Game()
{
	drawableField.clear();
	drawableField.shrink_to_fit();
}
void Game::Play(Player* player1,Player* player2)
{
	system("CLS");

	this->player1 = player1;
	this->player2 = player2;

	DrawFields();
	Cycle();
}
void Game::Cycle()
{
	while(isGameEnded == 0)
	{
		srand(time(0));
		Sleep(1000);
		cout << endl;

		switch(numberOfPlayerToMove)
		{
		case 0:
			MakeAMove(player1, player2, numberOfPlayerToMove);
			break;
		case 1:
			MakeAMove(player2, player1, numberOfPlayerToMove);
			break; 
		}
		CheckForWinner(player1, player2);
		CheckForWinner(player2, player1);
	}
}
void Game::MakeAMove(Player* attacking,Player* defending,int playerNumber)
{
	Point hitPoint = Attack(attacking,defending);
	bool hit = CheckHit(defending, hitPoint);
	DefineNextPlayerToMove(playerNumber, hit);
	ChangeShipsVisibilityIfHumans(attacking, defending);
	DrawFields();
	UI::WriteInfoAboutMove(hitPoint, attacking->GetName(), hit);
}
void Game::ChangeShipsVisibilityIfHumans(Player* attacking, Player* defending)
{
	if (attacking->GetType() == PlayerType::hum && defending->GetType() == PlayerType::hum)
	{
		attacking->SetShipsVisibility(true);
		defending->SetShipsVisibility(false);
	}
}
void Game::DrawFields()
{
	system("CLS");
	Drawer::Draw(drawableField, player1);
	cout << endl;
	Drawer::Draw(drawableField, player2);
}
Point Game::Attack(Player* player,Player * defending)
{
	if (player->GetType() == PlayerType::hum)
		return UI::AskForAttack();
	else
		return GenerateAttackPoint(player,defending->ships);
}
Point Game::GenerateAttackPoint(Player* player,vector<Ship> enemyShips)
{
	Point generatingPoint;
      do
	  {
		  int x = rand() % (Values::width - 1) + 1;
		  int y = rand() % (Values::height - 1) + 1;
		  generatingPoint = Point(x, y);
	  } while(ifContainsPoint(player,generatingPoint) && ifShipAlreadyShot(enemyShips,generatingPoint));
	  return generatingPoint;
}
bool Game::ifContainsPoint(Player * player,Point point)
{
	if (find(player->missesOnThisPlayerField.begin(), player->missesOnThisPlayerField.end(), point) == player->missesOnThisPlayerField.end())
		return true; // contains
	else
		return false; // doesn`t
}
bool Game::ifShipAlreadyShot(vector<Ship> ships,Point pointToCheck)
{
	for (Ship ship : ships)
	{
		if (ship.coords == pointToCheck && ship.state == ShipState::destroyed)
			return true;
	}
	return false;
}
bool Game::CheckHit(Player * playerToHit,Point point)
{
	bool hitShip = false;
	for(int i =0;i<playerToHit->GetShipsQuantity(); i++)
	{
		if (playerToHit->ships[i].coords == point)
		{
			playerToHit->ships[i].state = ShipState::destroyed;
			hitShip = true;
		}
	}
	if (!hitShip)
	{
		playerToHit->missesOnThisPlayerField.push_back(point);
	}
	return hitShip;
}
void Game::DefineNextPlayerToMove(int numberPlayerThatMoved,bool hit)
{
	if (hit)
	{
		return;
	}
	else
	{
		if (numberPlayerThatMoved == 0)
			numberOfPlayerToMove+=1;
		else
			numberOfPlayerToMove -= 1; //kostil4iki
	}
}
void Game::CheckForWinner(Player * playerToLose,Player* playerToWin)
{
	for(const Ship& ship:playerToLose->ships)
	{
		if (ship.state == ShipState::alive)
			return;
	}
	isGameEnded = true;
	UI::DeclareAWinner(playerToWin->GetName());
	playerToWin->AddWin();
}