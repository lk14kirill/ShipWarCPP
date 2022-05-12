#pragma once
#include <iostream>
#include "Values.h"

using namespace std;

class PlayerProfile
{
public:
	PlayerProfile(string name, int wins, PlayerType type, string login, string password);
	PlayerProfile();
	string GetName();
	int GetWins();
	PlayerType GetType();
	string GetLogin();
	string GetPassword();
private:
	string name;
	int wins;
	PlayerType type;
	string login;
	string password;
};

