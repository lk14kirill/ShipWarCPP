#include <iostream>
#include "Lobby.h"

int main()
{
    Lobby * lobby = new Lobby();
    lobby->Start();
    delete lobby;
}