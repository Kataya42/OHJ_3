#include "chaser.h"

Chaser::Chaser()
{
    xSpeed_ = 0;
    ySpeed_ = 0;
    playercontrolled_ = false;
    maxspeed_ = 10;
    acceleration_ = 1;
}

std::string Chaser::getName() const
{
    return name_;
}

Interface::Location Chaser::giveLocation() const
{
    return location_;
}

void Chaser::move(Interface::Location loc)
{
    location_ = loc;
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

void Chaser::updateLocation(int hor, int ver)
{
    location_.setXY(location_.giveX() + 3 * hor, location_.giveY() + 3 * ver);
}

void Chaser::chase(std::shared_ptr<Interface::IActor> target)
{
    Interface::Location targetloc = target->giveLocation();
    if (targetloc.giveX() > location_.giveX()) {
        if (xSpeed_ <= maxspeed_) {
            xSpeed_ += acceleration_;
        }
    } else {
        if (xSpeed_ >= -maxspeed_) {
            xSpeed_ += -acceleration_;
        }
    }
    if (targetloc.giveY() > location_.giveY()) {
        if (ySpeed_ <= maxspeed_) {
            ySpeed_ += acceleration_;
        }
    } else {
        if (ySpeed_ >= -maxspeed_) {
            ySpeed_ += -acceleration_;
        }
    }
    location_.setXY(location_.giveX() + xSpeed_, location_.giveY() + ySpeed_);
}

void Chaser::isClose(std::shared_ptr<Interface::IActor> target)
{

}

void Chaser::setPlayerControlled(bool player2)
{
    playercontrolled_ = player2;
}

bool Chaser::getPLayerControlled()
{
    return playercontrolled_;
}

int Chaser::getSID() const
{
    return SID_;
}

void Chaser::setSID(int sid)
{
    SID_ = sid;
}
