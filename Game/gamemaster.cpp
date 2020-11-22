#include "gamemaster.h"
#include "manse.h"

GameMaster::GameMaster(QObject *parent) : QObject(parent)
{

}

void GameMaster::getcity(std::shared_ptr<Manse> city)
{
    city_ = city;
}

void GameMaster::getWindow(std::shared_ptr<GameWindow> window)
{
    window_ = window;
}

void GameMaster::runbusses()
{
    connect(&timer_, SIGNAL(timeout()), this, SLOT(updateDraw()));
    timer_.start(100);
}

void GameMaster::updateDraw()
{
    std::shared_ptr<Interface::IActor> i = city_->getBuses().at(city_->getBuses().size()-1);
    Interface::Location a = i->giveLocation();
    window_->updateCoords(a.giveX(),a.giveY());
}
