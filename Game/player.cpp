#include "player.h"

Player::Player()
{
}

Interface::Location Player::giveLocation() const
{
    if (locationset_) {
        return location_;
    }
    else {
        throw Interface::GameError("actor wasn't given a location");
    }
}

void Player::move(Interface::Location loc)
{
    // default coordinates defined in chaser.h
    if (not(loc.giveNorthernCoord() == DEFAULT_NORTHCOORD and
            loc.giveEasternCoord() == DEFAULT_EASTCOORD)) {
        location_ = loc;
        locationset_ = true;
    }
    else {
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

void Player::updateLocation(int hor, int ver)
{
    if (locationset_) {
        location_.setXY(location_.giveX() + SPEED * hor, location_.giveY() + SPEED * ver);
    }
    else {
        throw Interface::GameError("player start location not set");
    }
}
