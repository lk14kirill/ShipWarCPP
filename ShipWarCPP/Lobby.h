#pragma once
class Player;
class Lobby
{
public:
	void Start();
	Player* player1;
	Player* player2;
	~Lobby();
private:
	void SetupPlayers();
	void UpdatePlayers();
};

