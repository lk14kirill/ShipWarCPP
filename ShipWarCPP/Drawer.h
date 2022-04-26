#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include "Player.h"

using namespace std;
class Drawer
{
public:
	void Draw(vector<vector<char>> field, Player* player);
	static void DrawColoredSymbol(int col,char symbol);
private:
	vector<vector<char>> ConcatArrayAndPlayer(vector<vector<char>> field,Player* player);
	vector<vector<char>> ConcatArrayAndMisses(vector<vector<char>> field, vector<Point> misses);
	vector<vector<char>> ConcatArrayAndShips(vector<vector<char>> field, vector<Ship> ships);
	vector<vector<char>> ConcatArrayAndDestroyedShips(vector<vector<char>> field, vector<Ship> ships);
	static void ChangeColor(int col);
	static void ResetColor();
};

