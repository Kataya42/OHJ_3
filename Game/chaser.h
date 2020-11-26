#ifndef CHASER_H
#define CHASER_H

#include "interfaces/ivehicle.hh"
#include "interfaces/icity.hh"
#include "interfaces/ipassenger.hh"
#include "core/location.hh"
#include "actors/stop.hh"

#include <iostream>
#include <QTime>
#include <memory>
#include <set>
#include <map>
#include <vector>

class Chaser : public Interface::IActor
{
public:
    Chaser();

    // ActorIF interface
    std::string getName() const;
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;
    void setCity(std::shared_ptr<Interface::ICity> city);

    //Chaser functionality
    void updateLocation(int hor, int ver);
    void chase(std::shared_ptr<Interface::IActor> target);
    void isClose(std::shared_ptr<Interface::IActor> target);
    void setPlayerControlled(bool player2);
    bool getPLayerControlled();

    int getSID() const;
    void setSID(int sid);
private:
    int xSpeed_;
    int ySpeed_;
    int acceleration_;
    int maxspeed_;
    bool playercontrolled_;
    std::string name_;
    std::shared_ptr<Interface::ICity> city_;
    Interface::Location location_;

    bool removed_;
    int SID_;
};

#endif // CHASER_H
