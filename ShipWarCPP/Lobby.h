#pragma once
class Player;
class DBManager;
class PlayerProfile;

class Lobby
{
public:
	void Start();
	Player* player1;
	Player* player2;
	DBManager* dbManager;
	~Lobby();
private:
	void SetupPlayers();
	void UpdatePlayers();
	PlayerProfile GetAccount();
};

