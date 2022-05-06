#include "Lobby.h"
#include "Game.h"
#include "Player.h"
#include "UI.h"
#include "Matchmaker.h"
#include <windows.h>
#include <tuple>

void Lobby::Start()
{
	int gamesCount = 0;

	UI::Greetings();
	SetupPlayers();
	do
	{
		if (gamesCount != 0 && UI::AskForUpdatingPlayers())
			SetupPlayers();
		else if(gamesCount != 0)
			UpdatePlayers();

		Game* game = new Game();
		game->Play(player1, player2);

		gamesCount++;

		Sleep(3000);
		UI::ShowResult(player1, player2, gamesCount);

		delete game;
	} while (UI::AskForGame());
}
Lobby::~Lobby()
{
	delete player1;
	delete player2;
}
void Lobby::SetupPlayers()
{
	int shipsQuantity = UI::AskForShipQuantity();

	PlayerType firstType = UI::AskForPlayerType();
	PlayerType secondType = UI::AskForPlayerType();
	tuple<bool, bool> areShipsHidden = Matchmaker::DefineWhosShipsAreHidden(firstType, secondType);


	player1 = new Player(shipsQuantity, firstType, get<0>(areShipsHidden));
	player2 = new Player(shipsQuantity, secondType, get<1>(areShipsHidden));
}
void Lobby::UpdatePlayers()
{
	int shipsQuantity = UI::AskForShipQuantity();
	player1->UpdateValues(shipsQuantity);
	player2->UpdateValues(shipsQuantity);
}