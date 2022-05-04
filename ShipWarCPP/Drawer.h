#pragma once
#include <vector>
#include <iostream>
#include <windows.h>

struct Point;
struct Ship;
class Player;

using namespace std;
class Drawer
{
public:
	static void Draw(vector<vector<char>> field, Player* player);
	static void DrawColoredSymbol(int col,char symbol);
private:
	static vector<vector<char>> ConcatArrayAndPlayer(vector<vector<char>> field,Player* player);
	static vector<vector<char>> ConcatArrayAndMisses(vector<vector<char>> field, vector<Point> misses);
	static vector<vector<char>> ConcatArrayAndShips(vector<vector<char>> field, vector<Ship> ships);
	static vector<vector<char>> ConcatArrayAndDestroyedShips(vector<vector<char>> field, vector<Ship> ships);
	static void ChangeColor(int col);
	static void ResetColor();
};

