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
#include "gamewindow.hh"


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
    void draw();
    std::vector<std::shared_ptr<Interface::IActor>> getBuses();

    void addWindow(std::shared_ptr<GameWindow> window);
private slots:
    void updateDraw();
private:
    QTime time_;
    bool gamestarted_;
    std::vector<std::shared_ptr<Interface::IStop>> stops_;
    std::vector<std::shared_ptr<Interface::IActor>> buses_;
    std::shared_ptr<GameWindow> city_;
};

#endif // MANSE_H
