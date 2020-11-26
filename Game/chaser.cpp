#include "chaser.h"

Chaser::Chaser()
{

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

void Chaser::chase(std::shared_ptr<Interface::IActor>)
{

}

void Chaser::isClose(std::shared_ptr<Interface::IActor>)
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
