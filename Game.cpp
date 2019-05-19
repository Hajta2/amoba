#include "Game.hpp"
#include "Buttons.hpp"

static const int meret=15;

Game::Game(){
    for(int i=0;i<meret*meret;i++)
        new FunctorButton(this,2+(i%15)*40,40+40*(i/15),40,40,[this](){this->asd();});
}

void Game::asd(){
}

void Game::message(std::string msg){
}

