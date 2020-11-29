#include "creategame.hh"
#include "manse.h"

//Header for this is in courseside, implementation here.
std::shared_ptr<Interface::ICity> Interface::createGame()
{
    std::shared_ptr<Manse> map = nullptr; // initializing the game city
    map = std::make_shared<Manse>();
    return map;
}
//Using this we would not be able to utilize any of manses non icity, functions, so we do not use this
