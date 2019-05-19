#ifndef GAME_HPP
#define GAME_HPP


#include "window.hpp"
#include "GameLogic.hpp"
#include "Text.hpp"
#include "Buttons.hpp"

class GameLogic;
class Game : public Window {
    const unsigned max_X=600;
    const unsigned max_Y=600;
    const int gridSize=max_X/SizeOfField;
    static const int SizeOfField=15;
    GameLogic*logic;
    bool gameGoing=false;
    bool wantToExit=false;
    std::vector<NavigationButton*> navig;

public:
    virtual void OpeningScreen() {};
    virtual void openGame() {};
    virtual void exit() {};
    virtual void endScreen() {};
    virtual void eventLoop() {};
    virtual void newGame() {};
};

#endif // GAME_HPP
