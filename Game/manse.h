#ifndef MANSE_H
#define MANSE_H

#include "actors/stop.hh"
#include "player.h"
#include "chaser.h"
#include <QTime>

const int X_MOD = 350; //offset for coordinates
const int Y_MOD = 550;
const int RANGE = 15; // range to suck energy from busses

class Manse : public Interface::ICity {
public:
    Manse();
    //Icity
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
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const override;

    /**
     * @brief getActors returns actors_
     * @return vector with shared pointer containing Iactors
     */
    std::vector<std::shared_ptr<Interface::IActor> > getActors();
    /**
     * @brief getPlayer returns player_
     * @return shared pointer to player actor
     */
    std::shared_ptr<Player> getPlayer();
    /**
     * @brief getEnemy returns enemy_
     * @return shared pointer to the enemy actor
     */
    std::shared_ptr<Chaser> getEnemy();
    /**
     * @brief getStops retuns stops_
     * @return vector with shared pointers containing Istop actors
     */
    std::vector<std::shared_ptr<Interface::IStop> > getStops();
    /**
     * @brief addEnemy adds Chaser class object as the enemy
     * @param Chaser class enemy actor
     */
    void addEnemy();
    /**
     * @brief addPlayer adds Player class object as the player
     * @param Player class player actor
     */
    void addPlayer();
    /**
     * @brief getProg updates current progress into Manse
     * @param integer progress (energy)
     */
    void getProg(int progress);

private slots:

private:
    std::shared_ptr<Player> player_;
    std::shared_ptr<Chaser> enemy_;

    std::vector<std::shared_ptr<Interface::IStop> > stops_;
    std::vector<std::shared_ptr<Interface::IActor> > actors_;

    QTime time_;
    bool gamestarted_;
    int prog_;
};

#endif // MANSE_H
