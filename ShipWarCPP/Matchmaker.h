#pragma once
#include <tuple>
#include "Values.h"

using namespace std;

class Matchmaker
{
public:
    static tuple<bool, bool> DefineWhosShipsAreHidden(PlayerType frst, PlayerType scnd);
};

