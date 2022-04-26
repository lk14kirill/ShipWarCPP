#include "Lobby.h"
void Lobby::Start()
{
	do
	{
		srand(time(0));
		Game* game = new Game();
		ui->Greetings();
		int shipsQuantity = ui->AskForShipQuantity();
		Player * player1 = new Player(shipsQuantity,PlayerType::hum,"human");
		Player * player2 = new Player(shipsQuantity,PlayerType::ai,"bot");
		game->Play(player1, player2,ui);



		delete player1;
		delete player2;
		delete game;
	} while (ui->AskForGame());
}
