#include "Game.h"
void Game::Play(Player* player1,Player* player2,UI* ui)
{
	system("CLS");

	this->player1 = player1;
	this->player2 = player2;
	this->ui = ui;
	isGameEnded = false;

	DrawFields();
	Update();
}
void Game::Update()
{
	while(isGameEnded == 0)
	{
		srand(time(0));
		Sleep(1500);
		cout << endl;

		switch(turn)
		{
		case PlayerTurn::first:
			MakeAMove(player1, player2, 1);
			break;
		case PlayerTurn::second:
			MakeAMove(player2, player1, 2);
			break; 
		}
		
		CheckForWinner(player1, player2);
		CheckForWinner(player2, player1);

	}
}
void Game::MakeAMove(Player* attacking,Player* defending,int playerNumber)
{
	Point hitPoint;
	bool hit = false;
	hitPoint = Attack(attacking,defending);
	hit = CheckHit(defending, hitPoint);
	DefineNextPlayerToMove(playerNumber, hit);
	DrawFields();
	ui->WriteInfoAboutMove(hitPoint, attacking->name, hit);
}
void Game::DrawFields()
{
	system("CLS");
	drawer->Draw(drawableField, player1);
	cout << endl;
	drawer->Draw(drawableField, player2);
}
Point Game::Attack(Player* player,Player * defending)
{
	if (player->type == PlayerType::hum)
		return ui->AskForAttack();
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
	for(int i =0;i<playerToHit->ships.size();i++)
	{
		if (playerToHit->ships[i].coords == point)
		{
			playerToHit->ships[i].state = ShipState::destroyed;
			hitShip = true;
		}
	}
	if (!hitShip)
		playerToHit->missesOnThisPlayerField.push_back(point);
	return hitShip;
}
void Game::DefineNextPlayerToMove(int playerNumber,bool hit)
{
	if (hit)
	{
		return;
	}
	else
	{
		if (playerNumber == 1)
			turn = PlayerTurn::second;
		else if (playerNumber == 2)
			turn = PlayerTurn::first;
	}
}
void Game::CheckForWinner(Player * playerToLose,Player* playerToWin)
{
	for(Ship ship:playerToLose->ships)
	{
		if (ship.state == ShipState::alive)
			return;
	}
	isGameEnded = true;
	ui->DeclareAWinner(playerToWin->name);
}