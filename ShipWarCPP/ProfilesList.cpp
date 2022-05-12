#include "ProfilesList.h"
#include "PlayerProfile.h"
bool ProfilesList::IsThereAccount(string login,string password)
{
	for(PlayerProfile& profile : profiles)
	{
		if (profile.GetLogin() == login && profile.GetPassword() == password)
			return true;
	}
	return false;
}
PlayerProfile ProfilesList::GetAccount(string login,string password)
{
	for (PlayerProfile& profile : profiles)
	{
		if (profile.GetLogin() == login && profile.GetPassword() == password)
			return profile;
	}
	return PlayerProfile();
}
void ProfilesList::AddAccount(PlayerProfile newProfile)
{
	profiles.push_back(newProfile);
}
ProfilesList::~ProfilesList()
{
	profiles.clear();
}