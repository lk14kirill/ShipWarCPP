#pragma once
#include <vector>

using namespace std;

class FieldGeneration
{
public:
	static vector<vector<char>> GenerateField(int width, int height);
private:
	static vector<vector<char>> PlaceNumbers(vector<vector<char>> field,int width,int height);
	static vector<vector<char>> PlaceLetters(vector<vector<char>> field,int width,int height);
}; 

