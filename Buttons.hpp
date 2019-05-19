#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "widgets.hpp"
#include <functional>
#include "GameLogic.hpp"
#include "Game.hpp"

class GameLogic;
class Game;


class Button: public Widget
{
protected:
    bool pushed=false;
    std::string name;
    bool showing=false;
public:
  Button (int x, int y, int sx, int sy,std::string _name): Widget(x,y,sx,sy), name(_name){};
  void draw() override{};
  void handle(genv::event ev) override{};
};

class NavigationButton:public Button{
protected:
    std::function<void()> funct;
    int keycode;
public:
    NavigationButton(int x,int y,int sx,int sy,std::string _name,std::function<void()> _f,int _key):Button(x,y,sx,sy,_name), funct(_f),keycode(_key){};
    void action()
    {
        showing=false;
        funct();
    }
    void draw();
    void handle(genv::event ev);
};


#endif // BUTTONS_HPP
