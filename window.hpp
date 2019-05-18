#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include <vector>
#include <string>


class Widget;

class Window {
protected:
  std::vector<Widget*> widgets;

public:
  void event_loop();
  void register_w(Widget *);
  virtual void message(std::string m) = 0;
  virtual ~Window();
};


#endif /* ifndef WINDOW_HPP_INCLUDED */
