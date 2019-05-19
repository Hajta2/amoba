#include "GameLogic.hpp"

int state(int i, int j)
{
    return stateOfField[i][j];
};

bool GameLogic::changeState(int i, int j)
{
    if (state(i,j)==0)
    {
        StateOfField[i][j]=player;
    }
}

bool GameLogic::ValidStep(int i,int j)
{
    return state(i,j)==0;
}

bool GameLogic::InARow(int x)
{
int row=0;
for(int i=0;i<SizeOfField;i++){
    for(int j=0; j<SizeOfField-x;j++){
        row=0;
        for(int k=0;k<x;k++){
            if(state(i,j+k)==player)
                row++;
            if(row<k)
                continue;
        }
        if(row==x)
            return true;
    }
}
return false;
}

bool GameLogic::InAColumn(int x)
{
    int column=0;
    for(int i=0; i<SizeOfField; i++)
    {
        for (int j=0; j<SizeOfField-x; j++)
        {
            column=0;
            for(int k=0; k<x; k++)
            {
                if(state(i+k,j)==player)
                {
                    column++;
                }
                if(column<k)
                {
                    continue;
                }
            }
            if (column==x)
            {
                return true;
            }
        }
    }
    return false;
}

bool GameLogic::Across(int x)
{
    int across=0;
    //balról jobbra átlósan
    for(int i=0; i<SizeOfField-x; i++)
    {
        for (int j=0; j<SizeOfField-x; j++)
        {
            across=0;
            for(int k=0; k<x; k++)
            {
                if(state(i+k,j+k)==player)
                {
                    across++;
                }
                if(across<k)
                {
                    continue;
                }
            }
            if (across==x)
            {
                return true;
            }
        }
    }
    //jobról balra átlósan
    for(int i=0; i<SizeOfField-x; i++)
    {
        for (int j=SizeOfField; j>x; j--)
        {
            across=0;
            for(int k=0; k<x; k++)
            {
                if(state(i+k,j-k)==player)
                {
                    across++;
                }
                if(across<k)
                {
                    continue;
                }
            }
            if (across==x)
            {
                return true;
            }
        }
    }
    return false;
}

bool GameLogic::won()
{
    if(stepsMade<ForTheWin*2-1) //ha még nem történt ennyi lépés összesen, akkor még senki nem gyõzhetett
    {
        return false;
    }
    if(Across(ForTheWin) || InAColumn(ForTheWin) || InARow(ForTheWin))
    {
        newGame(); //lenullazom a state matrixot
        return true;
    }
    else
    {
        return false;
    }
}

bool GameLogic::isFull()
{
    for (int i=0; i<SizeOfField; i++)
    {
        for (int j=0; j<SizeOfField; j++)
        {
            if(state(i,j)==0)
            {
                return false;
            }
        }
    }
    return true;
}

void GameLogic::newGame()
{
    for(int i=0; i<sizeOfField; i++)
    {
        for(int j=0; j<sizeOfField; j++)
        {
            stateOfField[i][j]=0;
        }
    }
}

void GameLogic::switchPlayer()
{
    if(player==1)
    {
        player=2;
    }
    else
    {
        player=1;
    }
}
