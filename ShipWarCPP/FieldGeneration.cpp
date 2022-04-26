#include "FieldGeneration.h"
#include "Values.h"
vector<vector<char>> FieldGeneration::GenerateField(int width,int height)
{
	vector<vector<char>> field(width, vector<char>(height));
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			field[i][j] = Values::freeCellSymbol;
		}
	}
	field = PlaceNumbers(field,width,height);
	field = PlaceLetters(field,width,height);
	return field;
}

vector<vector<char>> FieldGeneration::PlaceNumbers(vector<vector<char>> field,int width,int height)
{
	int number = Values::asciiNumberStart;
	for(int i =1;i<field[0].size();i++)
	{
		field[0][i] = number;
		number++;
	}
	return field;
}
vector<vector<char>> FieldGeneration::PlaceLetters(vector<vector<char>> field, int width, int height)
{
	int letter = Values::asciiLetterStart;
	for (int i = 1; i < field.size(); i++)
	{
		field[i][0] = letter;
		letter++;
	}
	return field;
}
