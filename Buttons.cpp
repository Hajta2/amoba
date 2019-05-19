#include "Buttons.hpp"
#include <iostream>

using namespace genv;

void NavigationButton::draw()
{
    gout << move_to(_x,_y) ;
    gout<< color(0,0,0) ;
    gout<< box(_size_x,_size_y) ;
    gout<< move_to(_x+3,_y+gout.cdescent()+gout.cdescent()+5) ;
    gout<< color(255,255,255) << text(name);
    showing=true;
}
void NavigationButton::handle(genv::event ev)
{
    if((isFocused(ev) && !focused) || ev.keycode==keycode)
    {
        action();
        focused=true;
    }
    else
    {
        focused=false;
    }
}




