#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include <vector>
#include <string>
#include "graphics.hpp"


class Widget;

class Window {
protected:
  std::vector<Widget*> widgets;
  genv::event ev;

public:
};


#endif /* ifndef WINDOW_HPP_INCLUDED */
