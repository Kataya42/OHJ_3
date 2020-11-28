#include "player.h"
#include "errors/gameerror.hh"

Player::Player()
{
}

Interface::Location Player::giveLocation() const
{
    if (locationset_)
    {
        return location_;
    } else {
        throw Interface::GameError("actor wasn't given a location");
    }
}

void Player::move(Interface::Location loc)
{
    if (not (loc.giveNorthernCoord() == 6700000 and loc.giveEasternCoord() == 3500000))
    {
        location_ = loc;
        locationset_ = true;
    } else {
        throw Interface::GameError("Location is not possible");
    }
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
    location_.setXY(location_.giveX() + SPEED * hor, location_.giveY() + SPEED * ver);
}
