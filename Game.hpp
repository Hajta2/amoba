#ifndef GAME_HPP
#define GAME_HPP


#include "window.hpp"
#include "GameLogic.hpp"
#include "Text.hpp"

class GameLogic;
class Game : public Window {
    GameLogic*logic;
    bool gameGoing=false;
    bool wantToExit=false;

public:
    virtual void OpeningScreen() {};
    virtual void openGame() {};
    virtual void exit() {};
    virtual void endScreen() {};
    virtual void eventLoop() {};
    virtual void newGame() {};
};

#endif // GAME_HPP
