#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP


class GameLogic
{
    protected:
        const unsigned max_X=300;
        const unsigned max_Y=300;
        const int gridSize=max_X/sizeOfField;
        static const int SizeOfField=15;
        const int ForTheWin=5;
        int StateOfField[SizeOfField][SizeOfField]={};
        int player=1;
        int stepsMade=0;

    public:
        int state(int i,int j);
        void changeState(int i,int j);
        bool ValidStep(int i,int j);
        bool InARow(int x);
        bool Across(int x);
        bool InAColumn(int x);
        void newGame();
        bool isFull();

        void switchPlayer ();
        int whichPlayer () {return player;};
        virtual bool won() {return false;};
        virtual bool validStep(int i, int j) {return false;};
        void stepMade() {stepsMade++;};
};

#endif // GAMELOGIC_HPP
