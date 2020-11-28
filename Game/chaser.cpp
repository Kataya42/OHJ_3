#include "chaser.h"
#include "errors/gameerror.hh"

Chaser::Chaser()
{
    xSpeed_ = 0;
    ySpeed_ = 0;
    playercontrolled_ = true;
    maxspeed_ = MAXSPEED;
    acceleration_ = ACCELERATION;
}

void Chaser::updateLocation(int hor, int ver)
{
    xSpeed_ += hor * acceleration_;
    if (xSpeed_ >= maxspeed_ or xSpeed_ <= -maxspeed_) {
        xSpeed_ -= hor * acceleration_;
    }
    ySpeed_ += ver * acceleration_;
    if (ySpeed_ >= maxspeed_ or ySpeed_ <= -maxspeed_) {
        ySpeed_ -= ver * acceleration_;
    }
    location_.setXY(location_.giveX() + xSpeed_, location_.giveY() + ySpeed_);
}

void Chaser::chase(std::shared_ptr<Interface::IActor> target)
{

    Interface::Location targetloc = target->giveLocation();
    if (targetloc.giveX() > location_.giveX()) {
        if (xSpeed_ <= maxspeed_) {
            xSpeed_ += acceleration_;
            positiveXMovement_ = true;
        }
    }
    else {
        if (xSpeed_ >= -maxspeed_) {
            xSpeed_ += -acceleration_;  
            positiveXMovement_ = false;
        }
    }
    if (targetloc.giveY() > location_.giveY()) {
        if (ySpeed_ <= maxspeed_) {
            ySpeed_ += acceleration_;  
            positiveYMovement_ = true;
        }
    }
    else {
        if (ySpeed_ >= -maxspeed_) {
            ySpeed_ += -acceleration_;
            positiveYMovement_ = false;
        }
    }

    location_.setXY(location_.giveX() + xSpeed_, location_.giveY() + ySpeed_);
}

bool Chaser::isClose(std::shared_ptr<Interface::IActor> target, int range)
{
    if (location_.isClose(target->giveLocation(), range)) {
        return true;
    }
    else {
        return false;
    }
}

std::string Chaser::getName() const
{
    return name_;
}

Interface::Location Chaser::giveLocation() const
{
    if (locationset_)
    {
        return location_;
    } else {
        throw Interface::GameError("actor wasn't given a location");
    }

}

void Chaser::move(Interface::Location loc)
{
    location_ = loc;
    locationset_ = true;
}

void Chaser::remove()
{
    removed_ = true;
}

bool Chaser::isRemoved() const
{
    return removed_;
}

void Chaser::setCity(std::shared_ptr<Interface::ICity> city)
{
    city_ = city;
}

void Chaser::setPlayerControlled(bool player2)
{
    playercontrolled_ = player2;
}

bool Chaser::getPLayerControlled()
{
    return playercontrolled_;
}

void Chaser::setMaxSpeed(int maxspeed)
{
    maxspeed_ = maxspeed;
}

void Chaser::setAcceleration(int acceleration)
{
    acceleration_ = acceleration;
}

int Chaser::getDirection(std::shared_ptr<Interface::IActor> target)
{
    int direction;

    Interface::Location targetloc = target->giveLocation();

    if (abs(targetloc.giveX() - location_.giveX()) > abs(targetloc.giveY() - location_.giveY()) ){
        if (positiveXMovement_){
            direction = RIGHT;
        } else {
            direction = LEFT;
        }
    } else {
        if (positiveYMovement_){
            direction = DOWN;
        } else {
            direction = UP;
        }
    }

    return direction;
}
