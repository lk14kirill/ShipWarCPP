#pragma once
#include <vector>
using namespace std;
class FieldGeneration
{
public:
	vector<vector<char>> GenerateField(int width, int height);
private:
	vector<vector<char>> PlaceNumbers(vector<vector<char>> field,int width,int height);
	vector<vector<char>> PlaceLetters(vector<vector<char>> field,int width,int height);
}; 

