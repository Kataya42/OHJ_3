#ifndef CHASER_H
#define CHASER_H

#include "core/location.hh"
#include "actors/stop.hh"
#include "cstdlib"
#include "ownactoritem.hh"

const int MAXSPEED = 10;
const int ACCELERATION = 1;
const int CORRECT_NORTHCOORD = 6700000;
const int CORRECT_EASTCOORD = 3500000;

/**
 * @file
 * @brief Describes a chaser class that can accelerate towards another actor
 */

class Chaser : public Interface::IActor {
public:
    Chaser();

    // ActorIF interface
    /*! @copydoc Interface::IActor::giveLocation() const; */
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;

    //Chaser functionality
    /**
     * @brief updateLocation accelerates chaser towards a direction
     * @param hor direction for acceleration
     * @param ver vertical direction for acceleration
     * @pre -
     * @post Chasers location is moved by direction * acceleration. Exception guarantee: strong
     * @exception GameError Starting location not set
     */
    void updateLocation(int hor, int ver);
    /**
     * @brief Accelerates Chaser towards target IActor
     * @param target, IActor towards which to accelerate
     * @pre -
     * @post Chaser has accelerated towards IActor. Exception guarantee: strong.
     * @exception GameError Target location not set
     */
    void chase(std::shared_ptr<Interface::IActor> target);
    /**
     * @brief Tells whether Chaser is close to target IActor
     * @param target, IActor which to check
     * @pre Chaser and target have locations. Exception guarantee: nothrow
     * @return true if close, false if not
     */
    bool isClose(std::shared_ptr<Interface::IActor> target, int range);
    /**
     * @brief setMaxSpeed sets max speed Chaser can reach by accelerating
     * @param maxspeed
     * @pre - Exception guarantee: nothrow
     * @post new maxspeed set
     */
    void setMaxSpeed(int maxspeed);
    /**
     * @brief setAcceleration sets factor by which chaser accelerates
     * @param acceleration
     * @pre - Exception guarantee: nothrow
     * @post new accelartion factor set
     */
    void setAcceleration(int acceleration);
    /**
     * @brief getDirection returns direction chaser is pointing towards for rotating model
     * @param target from which direction is calculated
     * @pre - Exception guarantee: nothrow
     * @return return direction towards which to turn chaser. See Ownactoritem for enum directions
     */
    int getDirection(std::shared_ptr<Interface::IActor> target);

private:
    bool locationValid(Interface::Location testloc);
    int xSpeed_;
    int ySpeed_;
    int acceleration_;
    int maxspeed_;
    int direction_ = 0;
    bool positiveXMovement_ = true;
    bool positiveYMovement_ = true;
    bool locationset_ = false;

    Interface::Location location_;

    bool removed_ = false;
};

#endif // CHASER_H
