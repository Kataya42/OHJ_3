#include "manse.h"
#include "errors/gameerror.hh"
#include "errors/initerror.hh"

Manse::Manse()
{
    gamestarted_ = false;
}

void Manse::setBackground(QImage& basicbackground, QImage& bigbackground)
{
    Q_UNUSED(basicbackground)
    background_ = bigbackground;
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
    if (prog_ >= 0) {
        return false;
    }
    else {
        return true;
    }
}

void Manse::addStop(std::shared_ptr<Interface::IStop> stop)
{
    if (not (stop->getLocation().giveNorthernCoord() == 6700000 and stop->getLocation().giveEasternCoord() == 3500000))
    {
        stops_.push_back(stop);
    } else
    {
        throw Interface::InitError("Stops position is not valid.");
    }

}

void Manse::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    if (findActor(newactor))
    {
        throw Interface::GameError("Actor is already in the city");
    } else
    {
        //this was the only way we figured out to seperate passengers from buses here
        if (stops_.size() == 0) {
            actors_.push_back(newactor);
        }
    }

}

void Manse::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    actor->remove();
}

void Manse::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    //This does not ever seem to be called
    actor->isRemoved();
}

bool Manse::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for (auto a : actors_) {
        if (a == actor) {
            return true;
        }
    }
    return false;
}

void Manse::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_UNUSED(actor)
}

std::vector<std::shared_ptr<Interface::IActor> > Manse::getNearbyActors(Interface::Location loc) const
{

    std::vector<std::shared_ptr<Interface::IActor> > close;

    for (auto a : actors_) {

        int nx = a->giveLocation().giveX();
        int ny = a->giveLocation().giveY();
        Interface::Location b;

        b.setXY(nx + X_MOD, Y_MOD - ny);

        if (b.isClose(loc, RANGE)) {
            close.push_back(a);
        }
    }
    return close;
}

std::vector<std::shared_ptr<Interface::IActor> > Manse::getActors()
{
    return actors_;
}

void Manse::addPlayer()
{
    if (not playeradded_)
    {
        std::shared_ptr<Player> player = nullptr;
        player = std::make_shared<Player>();

        Interface::Location start;
        start.setXY(480, 316);

        player->move(start);

        player_ = player;
        playeradded_ = true;
    }
}

std::shared_ptr<Player> Manse::getPlayer()
{
    if (playeradded_)
    {
        return player_;
    } else
    {
        throw Interface::GameError("player not added yet");
    }

}

void Manse::addEnemy()
{
    if (not enemyadded_)
    {
        std::shared_ptr<Chaser> enemy = nullptr;
        enemy = std::make_shared<Chaser>();

        Interface::Location enemyStart;
        enemyStart.setXY(500, 500);
        enemy->move(enemyStart);

        enemy_ = enemy;
        enemyadded_ = true;
    }
}

std::shared_ptr<Chaser> Manse::getEnemy()
{
    if (enemyadded_)
    {
        return enemy_;
    } else
    {
        throw Interface::GameError("enemy not added yet");
    }

}

std::vector<std::shared_ptr<Interface::IStop> > Manse::getStops()
{
    return stops_;
}

void Manse::getProg(int progress)
{
    prog_ = progress;
}
