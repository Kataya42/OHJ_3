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
#include "ownactoritem.hh"
#include "player.h"
#include "chaser.h"
#include "core/location.hh"

#include <iostream>
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
    void setBackground(QImage& basicbackground, QImage& bigbackground) override;
    void setClock(QTime clock) override;
    void startGame() override;
    bool isGameOver() const override;

    void addStop(std::shared_ptr<Interface::IStop> stop) override;
    void addActor(std::shared_ptr<Interface::IActor> newactor) override;
    void removeActor(std::shared_ptr<Interface::IActor> actor) override;
    void actorRemoved(std::shared_ptr<Interface::IActor> actor) override;
    bool findActor(std::shared_ptr<Interface::IActor> actor) const override;
    void actorMoved(std::shared_ptr<Interface::IActor> actor) override;
    std::vector<std::shared_ptr<Interface::IActor>> getNearbyActors(Interface::Location loc) const override;
    std::vector<std::shared_ptr<Interface::IActor>> getBuses();

    void addPlayer(std::shared_ptr<Player> p);
    std::shared_ptr<Player> getPlayer();
    void addEnemy(std::shared_ptr<Chaser> e);
    std::shared_ptr<Chaser> getEnemy();
    std::vector<std::shared_ptr<Interface::IStop>> getStops();
    void getProg(int progress);

private slots:

private:
    QTime time_;
    bool gamestarted_;
    std::shared_ptr<Player> player_;
    std::shared_ptr<Chaser> enemy_;
    std::vector<std::shared_ptr<Interface::IStop>> stops_;
    std::vector<std::shared_ptr<Interface::IActor>> buses_;
    std::vector<std::shared_ptr<Interface::IActor>> close_;
    int prog_ = 0;

};

#endif // MANSE_H
