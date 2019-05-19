#include "Board.hpp"
#include "Text.hpp"

using namespace genv;

Board::Board(){
GameLogic * gl=new GameLogic(this);
logic=gl;
    std::string openGame="Click here or press enter to play.";
    NavigationButton * open = new NavigationButton(max_X/2-gout.twidth(openGame)/2,max_Y/2,gout.twidth(openGame),20,openGame,[this](){this->newGame();},key_enter);
    navig.push_back(open);
    std::string endGame="Click here or press escape to exit.";
    NavigationButton * exit= new NavigationButton(max_X/2-gout.twidth(endGame)/2,3*max_Y/4,gout.twidth(endGame),20,endGame, [this](){this->exit();},key_escape);
    navig.push_back(exit);
OpeningScreen();
}

void Board::EmptyField(){
gout<<move_to(0,0)<<color(255,250,250)<<box(max_X,max_Y);
gout<<color(0,0,0);
for(int i=1;i<SizeOfField;i++){
    gout<<move_to(i*gridSize,0)<<line(0,max_Y);
    gout<<move_to(0,i*gridSize)<<line(max_X,0);
}
gout<<refresh;
}
