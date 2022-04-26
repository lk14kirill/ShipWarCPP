#include "UI.h"
#include "Drawer.h"
void UI::Greetings()
{
	system("CLS");
	//setting green color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "------------------" << endl;
	cout << "Welcome to ship war!" << endl;
	Drawer::DrawColoredSymbol(Values::shipColor, Values::shipSymbol);
	SetConsoleTextAttribute(hConsole, 10);
	cout << " - ship" << endl;
	Drawer::DrawColoredSymbol(Values::missedColor, Values::missSymbol);
	SetConsoleTextAttribute(hConsole, 10);
	cout << " - missed" << endl;
	Drawer::DrawColoredSymbol(Values::destroyedShipColor, Values::destroyedSymbol);
	SetConsoleTextAttribute(hConsole, 10);
	cout << " - destroyed" << endl;
	cout << "Every ship is single-deck" << endl;
	cout << endl;
	cout << "Type something to start." << endl;
	cout << "------------------" << endl;
	//returning white color
	SetConsoleTextAttribute(hConsole, 15);
	char s;
	cin >>s;
}
bool UI::AskForGame()
{
	cout << "Do you want to play again?Y/n" << endl;
	string answer = "";
    while(true)
	{
		cin >> answer;
		if (tolower(answer[0]) == 'n')
			return false;
		if (tolower(answer[0]) == 'y')
			return true;
		cout << "Type y or n."<< endl;
	}
	return false;
}
int UI::AskForShipQuantity()
{
	system("CLS");
	cin.ignore();
    int quant;
	int maximum = (Values::width - 1) * (Values::height - 1);

	while(true)
	{
		cout << "Type quantity of ships(between 1 and " << maximum << ")" << endl;
		cin >> quant;
		if (quant > 0 && quant <= maximum)
			return quant;
	}
}
Point UI::AskForAttack()
{
	string symbols = "0Z";
	while (!IsInRange(symbols))
	{
		cout << "Write your attack point!Example: 7D,4f" << endl;
		cin>>symbols;
	}
	return Point(toupper(symbols[1]) - 64, symbols[0] - '0');
}
bool UI::IsInRange(string symbols)
{
	if (symbols[0] - '0' > Values::height || symbols[0] - '0' < 1 || toupper(symbols[1]) - 64 < 1 || toupper(symbols[1]) - 64 > Values::width)
		return false;
	else
		return true;
}
void UI::DeclareAWinner(string name)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << name << " has won the game!";
	SetConsoleTextAttribute(hConsole, 15);
}
void UI::WriteInfoAboutMove(Point hitPoint,string name,bool hit)
{
	string point = to_string(hitPoint.y) + (char)(hitPoint.x + 64);
	if (hit)
	{
		cout << name << " hit " << point << "!" << endl;
	}
	else
	{
		cout << name << " missed at " << point << "!" << endl;
	}
}