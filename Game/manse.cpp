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
    if (prog_ >= 0){
        return false;
    } else {
        return true;
    }
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
    //kekw
    std::cout << "yes actorRemoved is used" << std::endl;
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

    for (auto a : buses_){

        int nx = a->giveLocation().giveX();
        int ny = a->giveLocation().giveY();
        Interface::Location b;
        b.setXY(nx+350, 500-ny+50);

        if (b.isClose(loc,10)){
            close.push_back(a);
            }
            //std::cout << "close yo" << std::endl;
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

void Manse::addEnemy(std::shared_ptr<Chaser> e)
{
    enemy_ = e;
}

std::shared_ptr<Chaser> Manse::getEnemy()
{
    return enemy_;
}

std::vector<std::shared_ptr<Interface::IStop> > Manse::getStops()
{
    return stops_;
}

void Manse::getProg(int progress)
{
    prog_ = progress;
}




