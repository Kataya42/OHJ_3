#include "manse.h"

Manse::Manse()
{
    gamestarted_ = false;
}

void Manse::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    //Currently test implementation in main, implementation here probably later
}

void Manse::setClock(QTime clock)
{
    time_ = clock;
}

void Manse::startGame()
{
    gamestarted_ = true;
}

bool Manse::isGameOver() const
{

}

void Manse::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
    Interface::Location a = stop->getLocation();
    int c = a.giveY();
    int b = a.giveX();
    std::cout << c << " " << b << std::endl;

}

void Manse::addActor(std::shared_ptr<Interface::IActor> newactor)
{

    actors_.push_back(newactor);
    Interface::Location a = newactor->giveLocation();
    int c = a.giveY();
    int b = a.giveX();

    std::cout << c << " " << b << std::endl;

}

void Manse::removeActor(std::shared_ptr<Interface::IActor> actor)
{

}

void Manse::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool Manse::findActor(std::shared_ptr<Interface::IActor> actor) const
{

}

void Manse::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

}

std::vector<std::shared_ptr<Interface::IActor> > Manse::getNearbyActors(Interface::Location loc) const
{

}

void Manse::draw()
{
    for ( auto i : stops_){
        Interface::Location a = i->getLocation();
        city_->addActor(a.giveX(),a.giveY(),1000);
    }

//    for ( auto i : actors_){
//        Interface::Location a = i->giveLocation();
//        city_->addActor(a.giveX()*0.2,a.giveY()*0.2,0);
//    }
}

void Manse::addWindow(std::shared_ptr<GameWindow> window)
{
    city_ = window;
}
