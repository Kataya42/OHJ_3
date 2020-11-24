#include "player.h"

Player::Player()
{

}

std::string Player::getName() const
{
    return name_;
}

Interface::Location Player::giveLocation() const
{
    return location_;
}

void Player::move(Interface::Location loc)
{
    location_ = loc;
}

void Player::remove()
{
    removed_ = true;
}

bool Player::isRemoved() const
{
    return removed_;
}

void Player::setCity(std::shared_ptr<Interface::ICity> city)
{
    city_ = city;
}

int Player::getSID() const
{
    return SID_;
}

void Player::setSID(int sid)
{
    SID_ = sid;
}
