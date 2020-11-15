#ifndef MANSE_H
#define MANSE_H
#include <interfaces/iactor.hh>
#include <interfaces/icity.hh>
#include <interfaces/ipassenger.hh>
#include <interfaces/istatistics.hh>
#include <interfaces/istop.hh>
#include "interfaces/ivehicle.hh"
#include "core/location.hh"
#include "actors/stop.hh"

#include <QTime>
#include <memory>
#include <set>
#include <map>
#include <vector>
#include <QImage>

class Manse : public Interface::ICity
{
public:
    Manse();

    //ICity
    void setBackground(QImage& basicbackground, QImage& bigbackground);
    void setClock(QTime clock);
    void startGame();
    bool isGameOver() const;

    void addStop(std::shared_ptr<Interface::IStop> stop);
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;
    void actorMoved(std::shared_ptr<Interface::IActor> actor);
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const;
};

#endif // MANSE_H
