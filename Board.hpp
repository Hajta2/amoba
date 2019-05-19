#ifndef BOARD_HPP
#define BOARD_HPP

#include "Game.hpp"



class Board: public Game{
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
