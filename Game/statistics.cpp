#include "statistics.hh"

Statistics::Statistics()
{

}

void Statistics::addScore()
{
    score_ += modifier_;
}


void Statistics::addPlayerEnergy()
{
    if (energy_ < 90){
       energy_ += 10;
    }

}

void Statistics::drainPlayerEnergy()
{
   energy_ --;
}


void Statistics::increaseModifier()
{
    modifier_ ++;
}

int Statistics::getScore()
{
    return score_;
}

int Statistics::getPlayerEnergy()
{
    return energy_;
}

double Statistics::getDistance()
{
    return distance_;
}
