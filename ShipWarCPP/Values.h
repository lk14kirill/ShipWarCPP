#pragma once
enum class ShipState {alive,destroyed};
enum class PlayerType {ai,hum};
enum class PlayerTurn {first,second};
class Values
{
public:
	const static int width = 11;
	const static int height = 10;
	const static int asciiNumberStart = 49;
	const static int asciiLetterStart = 65;
	const static int shipColor = 14;
	const static int destroyedShipColor = 12;
	const static int missedColor = 15;
	const static char shipSymbol = 254;
	const static char missSymbol = 177;
	const static char destroyedSymbol = 178;
	const static char freeCellSymbol = 176;
};

