#include "Board.hpp"
#include "Text.hpp"
#include <math.h>

using namespace genv;

Board::Board(){
    logic=new GameLogic(this);
    std::string openGame="Kattints ide, vagy nyomj ENTERT, ha j�tszani szeretn�l";
    NavigationButton * open = new NavigationButton(max_X/2-gout.twidth(openGame)/2,max_Y/2,gout.twidth(openGame),20,openGame,[this](){this->newGame();},key_enter);
    navig.push_back(open);
    std::string endGame="Kattints ide, vagy nyomj ESCAPE-t, ha ki szeretn�l l�pni";
    NavigationButton * exit= new NavigationButton(max_X/2-gout.twidth(endGame)/2,3*max_Y/4,gout.twidth(endGame),20,endGame, [this](){this->exit();},key_escape);
    navig.push_back(exit);
    OpeningScreen();
}

void Board::EmptyField(){
gout<<move_to(0,0)<<color(0,0,0)<<box(max_X,max_Y);
gout<<color(255,255,255);
for(int i=1;i<SizeOfField;i++){
    gout<<move_to(i*gridSize,0)<<line(0,max_Y);
    gout<<move_to(0,i*gridSize)<<line(max_X,0);
}
gout<<refresh;
}

void Board::eventLoop(){
while(gin>>ev && !wantToExit)
    {

        if(ev.type==ev_mouse && ev.button==btn_left && logic->ValidStep(whichLine(),whichRow()))
        {
            if(logic->whichPlayer()==1)
    {
        gout<<color(0,0,0);
        gout<<move_to(whichLine()*gridSize+1, whichRow()*gridSize+1)<<box(gridSize-2,gridSize-2);
        gout<< move_to(whichLine()*gridSize+gridSize/2-5, whichRow()*gridSize+gridSize/2)<< color(255,255,255)<<text("X");
        logic->changeState(logic->whichPlayer(),whichLine(),whichRow());
        logic->stepMade();
        logic->switchPlayer();
        if(logic->won())
        endScreen();
    }
    else if(logic->whichPlayer()==2)
    {
        gout<<color(0,0,0);
        gout<<move_to(whichLine()*gridSize+1, whichRow()*gridSize+1)<<box(gridSize-2,gridSize-2);
        gout<< move_to(whichLine()*gridSize+gridSize/2-5, whichRow()*gridSize+gridSize/2)<< color(255,255,255)<<text("O");
        logic->changeState(logic->whichPlayer(),whichLine(),whichRow());
        logic->stepMade();
        logic->switchPlayer();
        if(logic->won())
        endScreen();
        }
        if(ev.type==ev_key)
        {
            for(unsigned j=0; j<navig.size(); j++)
            {
                navig[j]->handle(ev);
            }
        }
    }
    /*else if(logic->isFull()){
        gameGoing=false;
    std::string who="D�NTETLEN";
    Text * whoWon;
    gout << move_to(0,0) << color(0,0,0) << box(max_X,max_Y);
    whoWon = new Text(max_X/2-gout.twidth(who)/2,max_Y/4,gout.twidth(who),20,who);
    whoWon->draw();
    for(unsigned i=0; i<navig.size(); i++)
    {
        navig[i]->draw();
    }
    gout << refresh;
    while(gin>>ev && !gameGoing)
    {
        for(unsigned i=0; i<navig.size(); i++)
        {
            navig[i]->handle(ev);
        }
    }
    delete whoWon;
    }*/
gout<<refresh;
}
}


int Board::whichLine()
{
    return floor(ev.pos_x/gridSize);
}

int Board::whichRow()
{
    return floor(ev.pos_y/gridSize);
}

void Board::OpeningScreen()
{
    gout.open(max_X,max_Y);
    std::string game="AM�BA";
    Text * gameName = new Text(max_X/2-gout.twidth(game)/2,max_Y/4,gout.twidth(game),20,game);
    gameName->draw();
    for(unsigned i=0; i<navig.size(); i++)
    {
        navig[i]->draw();
    }
    gout << refresh;
    while(gin>>ev && !gameGoing)
    {
        for(unsigned i=0; i<navig.size(); i++)
        {
            navig[i]->handle(ev);
        }
    }
    delete gameName;
    EmptyField();
}

void Board::endScreen()
{
    gameGoing=false;
    int player=logic->whichPlayer();
    std::string who=std::to_string(player) + ". J�t�kos nyert!";
    Text * whoWon;
    gout << move_to(0,0) << color(0,0,0) << box(max_X,max_Y);
    whoWon = new Text(max_X/2-gout.twidth(who)/2,max_Y/4,gout.twidth(who),20,who);
    whoWon->draw();
    for(unsigned i=0; i<navig.size(); i++)
    {
        navig[i]->draw();
    }
    gout << refresh;
    while(gin>>ev && !gameGoing)
    {
        for(unsigned i=0; i<navig.size(); i++)
        {
            navig[i]->handle(ev);
        }
    }
    delete whoWon;
}

void Board::exit()
{
    wantToExit=true;
    for(unsigned i=0; i<widgets.size(); i++)
    {
        delete widgets[i];
    }
    for(unsigned i=0; i<navig.size(); i++)
    {
        delete navig[i];
    }
    delete logic;
    std::exit(0);
}


void Board::newGame()
{
    EmptyField();
    for(unsigned i=0; i<widgets.size(); i++)
    {
        delete widgets[i];
    }
    eventLoop();
}
