#pragma once
#include <vector>
#include <string>
#include "Values.h"

struct Ship;
struct Point;

using namespace std;
class Player
{
public:
	Player(int shipsQuantity, PlayerType type,bool areShipsHidden);
	~Player();
	vector<Point> missesOnThisPlayerField;
	vector<Ship> ships;
    
	void UpdateValues(int shipsQuantity);
	void SetShipsVisibility(bool areHidden);
	void AddWin();
	int GetWins();
	int GetShipsQuantity();
	bool AreShipsHidden();
	PlayerType GetType();
	string GetName();
private:
	PlayerType type;
	string name;
	bool areShipsHidden = false;
	int shipsQuantity;
	int wins = 0;
};


