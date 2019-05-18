#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "widgets.hpp"
#include <functional>


class Buttons: public Widget
{
public:
  Buttons(Window *w, int x, int y, int sx, int sy);
  void draw() override;
  void handle(genv::event ev) override;
  virtual void action() = 0;
};

class FunctorButton: public Buttons{
std::function<void()> fv;
public:
    FunctorButton(Window *w,int x,int y,int sx,int sy, std::function<void()> _fv);
    void action() override;
};



#endif // BUTTONS_HPP
