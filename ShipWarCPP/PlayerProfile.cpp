#include "PlayerProfile.h"
PlayerType PlayerProfile::GetType() { return type; }
string PlayerProfile::GetLogin() { return login; }
string PlayerProfile::GetPassword() { return password; }
string PlayerProfile::GetName() { return name; }
int PlayerProfile::GetWins() { return wins; }

PlayerProfile::PlayerProfile(string name, int wins, PlayerType type, string login, string password)
{
	this->name = name;
	this->wins = wins;
	this->type = type;
	this->login = login;
	this->password = password;
}
PlayerProfile::PlayerProfile()
{
	this->name = " ";
	this->wins = 0;
	this->type = PlayerType::ai;
	this->login = "bot";
	this->password = "bot";
}
