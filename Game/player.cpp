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

void Player::updateLocation(int hor, int ver)
{
    location_.setXY(location_.giveX() + 3 * hor, location_.giveY() + 3 * ver);
}
