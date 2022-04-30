#include "Lobby.h"
void Lobby::Start()
{
	do
	{
		srand(time(0));
		Game* game = new Game();
		UI::Greetings();
		int shipsQuantity = UI::AskForShipQuantity();
		Player * player1 = new Player(shipsQuantity,PlayerType::hum,"Human");
		Player * player2 = new Player(shipsQuantity,PlayerType::ai,"Bot");
		game->Play(player1, player2);

		delete player1;
		delete player2;
		delete game;
	} while (UI::AskForGame());
}
