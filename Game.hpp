#ifndef GAME_HPP
#define GAME_HPP


#include "widgets.hpp"



    class Game : public Window {
public:
  Game();
  void message(std::string msg) override;
};

#endif // GAME_HPP
