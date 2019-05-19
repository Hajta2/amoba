#ifndef BOARD_HPP
#define BOARD_HPP

#include "Game.hpp"
#include "Buttons.hpp"


class Board: public Game{
    std::vector<NavigationButton*> navig;
    GameLogic * logic;
    public:
        Board();
        void OpeningScreen();
        void EmptyField();
        void newGame();
        void exit();
        void endScreen();
        void eventLoop();
        void NewField();
        int whichLine();
        int whichRow();

};

#endif // BOARD_HPP
