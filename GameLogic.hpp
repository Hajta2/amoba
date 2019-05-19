#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "Game.hpp"
class Game;
class GameLogic
{
        const unsigned max_X=600;
        const unsigned max_Y=600;
        const int gridSize=max_X/SizeOfField;
        static const int SizeOfField=15;
        const int ForTheWin=5;
        int StateOfField[SizeOfField][SizeOfField]={};
        int player=1;
        int stepsMade=0;
        Game * game;

    public:
        GameLogic(Game * _game):game(_game){};
        int state(int i,int j);
        void changeState(int player,int i,int j);
        bool ValidStep(int i,int j);
        bool InARow(int x);
        bool Across(int x);
        bool InAColumn(int x);
        void newGame();
        bool isFull();
        bool won();
        void switchPlayer ();
        int whichPlayer () {return player;};
        void stepMade() {stepsMade++;};
};

#endif // GAMELOGIC_HPP
