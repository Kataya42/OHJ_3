#ifndef STATISTICS_HH
#define STATISTICS_HH

class Statistics {
public:
    Statistics();
    void addScore();
    int getScore();
    void addPlayerEnergy();
    void drainPlayerEnergy();
    int getPlayerEnergy();
    double getDistance();
    void increaseModifier();

private:
    int score_ = 0;
    int energy_ = 100;
    int modifier_ = 1;
    double distance_; // UNUSED
};

#endif // STATISTICS_HH
