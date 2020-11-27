#ifndef PLAYER_H
#define PLAYER_H

#include "actors/stop.hh"

const int SPEED = 3;

class Player : public Interface::IActor {
public:
    Player();

    // ActorIF interface
    std::string getName() const;
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;
    void setCity(std::shared_ptr<Interface::ICity> city);

    //Player functionality
    void updateLocation(int hor, int ver);

private:
    int movementDirection_;
    std::string name_;
    std::shared_ptr<Interface::ICity> city_;
    Interface::Location location_;

    bool removed_;
    int SID_;
};

#endif // PLAYER_H
