#include "Lobby.h"
#include "Game.h"
#include "Player.h"
#include "UI.h"
#include "Matchmaker.h"
#define byte char
#include <windows.h>
#include <tuple>
#include "DBManager.h"
#include "PlayerProfile.h"

void Lobby::Start()
{
	int gamesCount = 0;

	dbManager = new DBManager();

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
	delete dbManager;
}
void Lobby::SetupPlayers()
{
	PlayerProfile firstProfile = GetAccount();
	PlayerProfile secondProfile = GetAccount();

	int shipsQuantity = UI::AskForShipQuantity();
		
	tuple<bool, bool> areShipsHidden = Matchmaker::DefineWhosShipsAreHidden(firstProfile.GetType(), secondProfile.GetType());

	player1 = new Player(firstProfile.GetName(), shipsQuantity, firstProfile.GetType(), get<0>(areShipsHidden));
	player2 = new Player(secondProfile.GetName(), shipsQuantity,secondProfile.GetType(), get<1>(areShipsHidden));
}
void Lobby::UpdatePlayers()
{
	int shipsQuantity = UI::AskForShipQuantity();
	player1->UpdateValues(shipsQuantity);
	player2->UpdateValues(shipsQuantity);
}
PlayerProfile Lobby::GetAccount()
{
	PlayerProfile profile;
	if (UI::DoYouHaveAccount())
	{
		tuple<string,string> logAndPswrd = UI::GetValuesForExistingAccount(dbManager);
		profile = dbManager->GetProfile(get<0>(logAndPswrd), get<1>(logAndPswrd));
	}
	else
	{
		profile = UI::GetValuesForNewAccount(dbManager);
		dbManager->AddProfileToDB(profile);
	}
	cout << "Player is ready" << endl;
	cout << endl;
	return profile;
}