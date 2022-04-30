#include "Drawer.h"
void Drawer::Draw(vector<vector<char>> field,Player* player)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	field = ConcatArrayAndPlayer(field,player);

	for (int i = 0; i < field[0].size(); i++)
	{
		for (int j = 0; j < field.size(); j++)
		{
			if (field[j][i] == Values::shipSymbol)
				DrawColoredSymbol(Values::shipColor, field[j][i]);
			else if (field[j][i] == Values::destroyedSymbol)
				DrawColoredSymbol(Values::destroyedShipColor, field[j][i]);
			else if (field[j][i] == Values::missSymbol)
				DrawColoredSymbol(Values::missedColor, field[j][i]);
			else
			    cout << field[j][i];
		}
		cout << endl;
	}
}
vector<vector<char>> Drawer::ConcatArrayAndPlayer(vector<vector<char>> field,Player* player)
{
	if (player->AreShipsHidden())
	{
		field = ConcatArrayAndMisses(field, player->missesOnThisPlayerField);
		return ConcatArrayAndDestroyedShips(field, player->ships);
	}
	else
	{
		field = ConcatArrayAndMisses(field, player->missesOnThisPlayerField);
		return ConcatArrayAndShips(field, player->ships);
	}

}
vector<vector<char>> Drawer::ConcatArrayAndMisses(vector<vector<char>> field, vector<Point> misses)
{
	for(Point point:misses)
	{
		field[point.x][point.y] = Values::missSymbol;
	}
	return field;
}
vector<vector<char>> Drawer::ConcatArrayAndShips(vector<vector<char>> field, vector<Ship> ships)
{
	for (Ship ship : ships)
	{
		if(ship.state == ShipState::destroyed)
		    field[ship.coords.x][ship.coords.y] = Values::destroyedSymbol;
		else
			field[ship.coords.x][ship.coords.y] = Values::shipSymbol;

	}
	return field;
}
vector<vector<char>> Drawer::ConcatArrayAndDestroyedShips(vector<vector<char>> field, vector<Ship> ships)
{
	for (Ship ship : ships)
	{
		if (ship.state == ShipState::destroyed)
			field[ship.coords.x][ship.coords.y] = Values::destroyedSymbol;
	}
	return field;
}
void Drawer::ChangeColor(int col)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, col);
}
void Drawer::ResetColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
}
void Drawer::DrawColoredSymbol(int col,char symbol)
{
	ChangeColor(col);
	cout << symbol;
	ResetColor();
}