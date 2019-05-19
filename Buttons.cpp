#include "Buttons.hpp"


using namespace genv;

void NavigationButton::draw()
{
    using namespace genv;
    gout << move_to(_x,_y) ;
    gout<< color(0,0,0) ;
    gout<< box(_size_x,_size_y) ;
    gout<< move_to(_x+3,_y+gout.cdescent()+gout.cdescent()+5) ;
    gout<< color(255,255,255) << text(name);
    showing=true;
}
void NavigationButton::handle(genv::event ev)
{
    if((is_selected(ev.pos_x,ev.pos_y) || ev.keycode==keycode))
    {
        action();
        focused=true;
    }
    else
    {
        focused=false;
    }
}

void GameButton::draw()
{
    using namespace genv;
    gout << move_to(_x,_y) ;
    gout<< color(255,250,250) ;
    gout<< box(_size_x,_size_y) ;
    gout<< move_to(_x+3,_y+gout.cdescent()+gout.cdescent()+5) ;
    gout<< color(0,0,0) << text(name);
}

void GameButton::changeName(std::string _newName)
{
    name=_newName;
}

void GameButton::eventHandler(genv::event ev)
{
    if(logic->whichPlayer()==1 && is_selected(ev.pos_x,ev.pos_y )
    {
        changeName("X");
    }
    else if(logic->whichPlayer()==2 && is_selected(ev.pos_x,ev.pos_y ) )
    {
        changeName("O");
    }
    else
    {
        return;
    }
    draw();
    logic->changeState(whichLine(),whichColumn());
    logic->stepMade();
    if(logic->won())
    {
        game->endScreen();
    }
    logic->switchPlayer();
    gout << refresh;

}

int GameButton::whichLine()
{
    return y/game->gridWidth();
}

int GameButton::whichColumn()
{
    return x/game->gridWidth();
}
