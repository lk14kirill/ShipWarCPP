#pragma once
#include<string>
#include<iostream>

class PlayerProfile;

using namespace std;

class DBManager
{
public:
    void AddProfileToDB(PlayerProfile profile);
	bool IsProfileValid(string login, string password);
	bool IsLoginUsed(string login);
	PlayerProfile GetProfile(string login, string password);
private:
	string user = "postgres";
	string password = "shipwarcpp";
	string port = "5432";
	string host = "localhost";
	string dbName = "ShipWar";
	string tableName = "\"Profiles\"";

	string connectionString = "host=" + host +
		" port=" + port +
		" dbname=" + dbName +
		" user=" + user +
		" password=" + password;
};

