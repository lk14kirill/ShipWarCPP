#pragma once
#include "Game.h"
#include "Player.h"
#include "UI.h"

class Lobby
{
public:
	void Start();
	~Lobby()
	{
		delete ui;
	}
private:
	UI * ui = new UI();
};

