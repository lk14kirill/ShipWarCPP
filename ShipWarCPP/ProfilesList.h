#pragma once
#include <vector>
#include <string>

using namespace std;

class PlayerProfile;

class ProfilesList
{
public:
	vector<PlayerProfile> profiles;
	
	bool IsThereAccount(string login, string password);
	PlayerProfile GetAccount(string login, string password);
	void AddAccount(PlayerProfile profile);
	~ProfilesList();
};

