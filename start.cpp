#include "start.hpp"
#include "Board.hpp"


start::start()
{
    game = new Board;
}

void start::Start()
{
    game->eventLoop();
}


