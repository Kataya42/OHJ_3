#ifndef PLAYER_H
#define PLAYER_H



#include "interfaces/ivehicle.hh"
#include "interfaces/icity.hh"
#include "interfaces/ipassenger.hh"
#include "core/location.hh"
#include "actors/stop.hh"

#include <QTime>
#include <memory>
#include <set>
#include <map>
#include <vector>

class Player : public Interface::IActor
{
public:
    Player(unsigned int line);

    // ActorIF interface
    std::string getName() const;

    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;
    void setCity(std::shared_ptr<Interface::ICity> city);



    int getSID() const;
    void setSID(int sid);
private:
    std::string name_;
    std::shared_ptr<Interface::ICity> city_;
    Interface::Location location_;

    bool removed_;
    int SID_;
};

