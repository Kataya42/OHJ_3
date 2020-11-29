#ifndef PLAYER_H
#define PLAYER_H

#include "actors/stop.hh"
#include "errors/gameerror.hh"
#include "chaser.h"

const int SPEED = 3; //pxls

class Player : public Interface::IActor {
public:
    Player();

    // ActorIF interface
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;

    //Player functionality
    /**
     * @brief updateLocation moves playerlocation
     * @param hor x factor by which to move
     * @param ver y factor by which to move
     * @pre - Exception guarantee: strong
     * @exception GameError player start location not set
     */
    void updateLocation(int hor, int ver);

private:
    int movementDirection_;
    Interface::Location location_;
    bool removed_ = false;
    bool locationset_ = false;

    bool locationvalid(Interface::Location testloc);
};

#endif // PLAYER_H
