#include <cctype>
#include <iostream>
#include "Player.h"
#define byte char
#include <windows.h>
#include "UI.h"
#include "Drawer.h"
#include "Point.h"
#include "PlayerProfile.h";
#include "DBManager.h"

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
bool UI::DoYouHaveAccount()
{
	WriteColoredSentence("Do you have account?Y/n", 11);
	while (true)
	{
		string answer = "";
		cin >> answer;
		if (tolower(answer[0]) == 'n')
			return false;
		if (tolower(answer[0]) == 'y')
			return true;
		cout << "Type y or n." << endl;
	}
	return false;
}
PlayerProfile UI::GetValuesForNewAccount(DBManager * dbManager)
{
	string name;
	string login;
	string password;
	WriteColoredSentence("---Account creation---", 11);
	WriteColoredSentence("Type your name(it will be shown in game)", 11);
	cin >> name;

	WriteColoredSentence("Type your login", 11);
	cin >> login;

	while (dbManager->IsLoginUsed(login))
	{
		WriteColoredSentence("This login is used.Type your login", 11);
		cin >> login;
	}

	WriteColoredSentence("Type your password", 11);
	cin >> password;
	return PlayerProfile(name, 0, AskForPlayerType(), login, password);
}
tuple<string,string> UI::GetValuesForExistingAccount(DBManager* dbManager)
{
    string login;  
	string password; 
	do
	{
		tuple<string,string> logAndPswrd= GetLoginAndPassword(); // neyveren
		login = get<0>(logAndPswrd);
		password = get<1>(logAndPswrd);

	} while (!dbManager->IsProfileValid(login, password));
	return make_tuple(login, password);
}
tuple<string,string> UI::GetLoginAndPassword()
{
	string login;
	string password;
	WriteColoredSentence("Type your login", 11);
	cin >> login;
	WriteColoredSentence("Type your password", 11);
	cin >> password;
	return make_tuple(login, password);
}
bool UI::AskForGame()
{
	WriteColoredSentence("Do you want to play again?Y/n", 15);
    while(true)
	{
	    string answer = "";
		cin >> answer;
		if (tolower(answer[0]) == 'n')
			return false;
		if (tolower(answer[0]) == 'y')
			return true;
		cout << "Type y or n."<< endl;
	}
	return false;
}
bool UI::AskForUpdatingPlayers()
{
	WriteColoredSentence("Do you want to change players?Y/n", 15);
	while (true)
	{
		string answer = "";
		cin >> answer;
		if (tolower(answer[0]) == 'n')
			return false;
		if (tolower(answer[0]) == 'y')
			return true;
		cout << "Type y or n." << endl;
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
		WriteColoredSentence("Type quantity of ships(between 1 and " + to_string(maximum) + ")", 11);
		cin >> quant;
		if (quant > 0 && quant <= maximum)
			return quant;
	}
}
Point UI::AskForAttack()
{
	string symbols = "0Z";
	cout << "Write your attack point!    Example: 7D,4f" << endl;
	cin.ignore();
	cin >> symbols;
	while (!IsInRange(symbols))
	{
		cin.ignore();
		WriteColoredSentence("Write within the field!", 12);
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
	WriteColoredSentence(name + " has won the game", 10);
}
void UI::WriteInfoAboutMove(Point hitPoint,string name,bool hit)
{
	string point = to_string(hitPoint.y) + (char)(hitPoint.x + 64);
	if (hit)
		WriteColoredSentence(name + " hit " + point + "!", 12);
	else
		WriteColoredSentence(name + " missed at " + point + "!", 14);
}
void UI::WriteColoredSentence(string sentence,int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << sentence << endl;
	SetConsoleTextAttribute(hConsole, 15);
}
PlayerType UI::AskForPlayerType()
{
	char input;
	while(true)
	{
       WriteColoredSentence("Choose player type h(human) or b(bot)", 10);
	   cin.ignore();
	   cin >> input;
	   input = tolower(input);
	   if (input == 'h' || input == 'b')
		   break;
	}
	return (input == 'h') ? PlayerType::hum : PlayerType::ai;
}
void  UI::ShowResult(Player* player1,Player* player2,int gamesCount)
{
	system("CLS");
	WriteColoredSentence(player1->GetName()+':' + to_string(player1->GetWins()) + "wins.", 10);
	WriteColoredSentence(player2->GetName() + ':' + to_string(player2->GetWins()) + "wins.", 10);
	WriteColoredSentence("Games played:"+to_string(gamesCount), 10);
	cout<<endl;
}