#include "Matchmaker.h"
#include "Player.h"
#include "UI.h"
tuple<bool,bool> Matchmaker::DefineWhosShipsAreHidden(PlayerType first,PlayerType second)
{
	if (first == PlayerType::ai && second == PlayerType::ai)
		return make_tuple(false, false);
	if (first == PlayerType::ai && second == PlayerType::hum)
		return make_tuple(true, false);
	return make_tuple(false, true);
} 