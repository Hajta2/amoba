#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include "window.hpp"


class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    bool focused=false;
public:
    Widget(int x, int y, int sx, int sy);
    bool isFocused(genv::event ev);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual ~Widget() = default;
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
