#include "widgets.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;


Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{}

bool Widget::isFocused(genv::event ev)
{
    if (ev.type==ev_mouse)
    {
        if(ev.pos_x>=_x && ev.pos_x<=_x+_size_x && ev.pos_y>=_y && ev.pos_y<=_y+_size_y && ev.button==btn_left && !focused)
        {
            return true;
        }
    }
    return false;
}






