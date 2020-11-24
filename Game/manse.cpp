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
//    Interface::Location a = stop->getLocation();
//    int c = a.giveY();
//    int b = a.giveX();
//    std::cout << c << " " << b << std::endl;

}

void Manse::addActor(std::shared_ptr<Interface::IActor> newactor)
{

    if (stops_.size() == 0)
    {
        Interface::Location a = newactor->giveLocation();
        int c = a.giveY();
        int b = a.giveX();

        std::cout << typeid(*newactor).name() << c << " " << b << std::endl;
        buses_.push_back(newactor);
    }
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

std::vector<std::shared_ptr<Interface::IActor>>Manse::getNearbyActors(Interface::Location loc) const
{

    std::vector<std::shared_ptr<Interface::IActor>> close;
    //does not work for some reason
    for (auto a : buses_){
        if (a->giveLocation().isClose(loc,10)){
            std::cout << "close yo" << std::endl;
        }
    }


    return close;
}

std::vector<std::shared_ptr<Interface::IActor>> Manse::getBuses()
{
    return buses_;
}


void Manse::addPlayer(std::shared_ptr<Player> p)
{
    player_ = p;
}

std::shared_ptr<Player> Manse::getPlayer()
{
    return player_;
}

std::vector<std::shared_ptr<Interface::IStop> > Manse::getStops()
{
     return stops_;
}



