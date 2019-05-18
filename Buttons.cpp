#include "Buttons.hpp"

using namespace genv;

Buttons::Buttons(Window *w, int x, int y, int sx, int sy):
  Widget(w, x, y, sx, sy) {}

void Buttons::draw() {
  gout << move_to(_x, _y) << color(90,60,90) << box(_size_x, _size_y);
}

void Buttons::handle(event ev) {
  if(ev.type == ev_mouse && ev.button == btn_left) {
    action();
  }
}


FunctorButton::FunctorButton(Window *w,int x,int y,int sx,int sy,std::function<void()> _fv):Buttons(w,x,y,sx,sy), fv(_fv){}

void FunctorButton::action(){
fv();
}
