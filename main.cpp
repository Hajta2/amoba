#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include "Game.hpp"
#include <vector>
#include <iostream>
#include "start.hpp"
#include "Board.hpp"
#include "GameLogic.hpp"
using namespace std;
using namespace genv;



int main() {
  start *amoba = new start();
  amoba->Start();
  delete amoba;
  return 0;
}
