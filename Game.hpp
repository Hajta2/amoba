#ifndef GAME_HPP
#define GAME_HPP
#include<vector>

#include "window.hpp"
#include "GameLogic.hpp"
#include "Text.hpp"


    const unsigned max_X=600;
    const unsigned max_Y=600;

class GameLogic;

class Game : public Window {
    protected:
    const int gridSize=max_X/SizeOfField;
    static const int SizeOfField=15;
    bool gameGoing=false;
    bool wantToExit=false;

public:
    virtual void OpeningScreen() {};
    virtual void openGame() {};
    virtual void exit() {};
    virtual void endScreen() {};
    virtual void eventLoop() {};
    virtual void newGame() {};
    int gridWidth() {return gridSize;};
};

#endif // GAME_HPP
