#include "Lobby.h"
#include "Game.h"
#include "Player.h"
#include "UI.h"
#include "Matchmaker.h"
#include <tuple>

void Lobby::Start()
{
	do
	{
		UI::Greetings();
		int shipsQuantity = UI::AskForShipQuantity();

		PlayerType firstType = UI::AskForPlayerType();
		PlayerType secondType = UI::AskForPlayerType();
		tuple<bool, bool> areShipsHidden = Matchmaker::DefineWhosShipsAreHidden(firstType, secondType);

 		Player * player1 = new Player(shipsQuantity,firstType,get<0>(areShipsHidden));
		Player * player2 = new Player(shipsQuantity,secondType, get<1>(areShipsHidden));

		Game* game = new Game();
		game->Play(player1, player2);

		delete player1;
		delete player2;
		delete game;
	} while (UI::AskForGame());
}
