#include "Text.hpp"

using namespace genv;

Text::Text(int x,int y,int sx,int sy,std::string _text): Widget(x,y,sx,sy), txt(_text)
{

}

void Text::draw(){
gout<< move_to(_x,_y)<<color(0,0,0)<<box(_size_x,_size_y);
gout<< move_to(_x+3,_y+17)<< color(255,0,0)<<text(txt);

}


