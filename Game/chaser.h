#ifndef CHASER_H
#define CHASER_H

#include "core/location.hh"
#include "actors/stop.hh"
#include "cstdlib"
#include "ownactoritem.hh"

const int MAXSPEED = 10;
const int ACCELERATION = 1;



/**
 * @file
 * @brief Describes a chaser class that can accelerate towards another actor
 */

class Chaser : public Interface::IActor {
public:
    Chaser();

    // ActorIF interface
    /*! @copydoc Interface::IActor::getName() const; */
    std::string getName() const;
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;
    void setCity(std::shared_ptr<Interface::ICity> city);

    //Chaser functionality
    /*!
     * \brief updateLocation accelerates chaser towards a direction
     * \param hor horizontal direction for acceleration
     * \param ver vertical direction for acceleration
     */
    void updateLocation(int hor, int ver);
    /**
     * @brief Accelerates Chaser towards target IActor
     * @param target, IActor towards which to accelerate
     * @pre Chaser and target have locations
     * @post Chaser has accelerated towards IActor
     */
    void chase(std::shared_ptr<Interface::IActor> target);
    /**
     * @brief Tells whether Chaser is close to target IActor
     * @param target, IActor which to check
     * @pre Chaser and target have locations
     * @return true if close, false if not
     */
    bool isClose(std::shared_ptr<Interface::IActor> target, int range);
    /**
     * @brief Sets Chaser playercontrolled state
     * @param true if playercontrolled, false if not
     * @post playercontrolled_ set as parameter
     */
    void setPlayerControlled(bool player2);

    bool getPLayerControlled();

    void setMaxSpeed(int maxspeed);

    void setAcceleration(int acceleration);

    int getDirection(std::shared_ptr<Interface::IActor> target);

private:
    int xSpeed_;
    int ySpeed_;
    int acceleration_;
    int maxspeed_;
    int direction_ = 0;
    bool playercontrolled_;
    bool positiveXMovement_ = true;
    bool positiveYMovement_ = true;

    std::string name_;
    std::shared_ptr<Interface::ICity> city_;
    Interface::Location location_;

    bool removed_;
    int SID_;
};

#endif // CHASER_H
