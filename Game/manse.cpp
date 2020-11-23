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
        //Interface::Location a = newactor->giveLocation();
        //int c = a.giveY();
        //int b = a.giveX();

        //std::cout << typeid(*newactor).name() << c << " " << b << std::endl;
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

std::vector<std::shared_ptr<Interface::IActor>> Manse::getNearbyActors(Interface::Location loc) const
{

}


std::vector<std::shared_ptr<Interface::IActor>> Manse::getBuses()
{
    return buses_;
}

void Manse::draw()
{
    for ( auto i : stops_){

        int x = i->getLocation().giveX() +1350 ;
        int y = 500 - i->getLocation().giveY()+ 50;

        std::cout <<"x:" << x << " y:" << y << std::endl;
        city_->addActor(x,y,0);
    }
       //
    // }

    for ( auto i : buses_){

        int x2 = i->giveLocation().giveX() +1350 ;
        int y2 = 500 - i->giveLocation().giveY()+ 50;
        city_->addActor(x2,y2,1000);
    }

}

void Manse::updateDraw()
{
    std::shared_ptr<Interface::IActor> i = buses_.at(buses_.size()-1);
    Interface::Location a = i->giveLocation();
    city_->updateCoords(a.giveX(),a.giveY());
}

void Manse::addWindow(std::shared_ptr<GameWindow> window)
{
    city_ = window;
}
