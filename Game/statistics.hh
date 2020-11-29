#ifndef STATISTICS_HH
#define STATISTICS_HH

class Statistics {
public:
    Statistics();
    /**
     * @brief addScore increases core by modifier_
     * @pre -
     * @post Exception guarantee: nothrow
     */
    void addScore();
    /**
     * @brief getScore
     * @return  current score of game
     * @pre -
     * @post Exception guarantee: nothrow
     */
    int getScore();
    /**
     * @brief addPlayerEnergy Increases player energy by ten if under 90
     * @pre -
     * @post Exception guarantee: nothrow
     */
    void addPlayerEnergy();
    /**
     * @brief drainPlayerEnergy Drains player energy by one
     * @pre -
     * @post Exception guarantee: nothrow
     */
    void drainPlayerEnergy();
    /**
     * @brief getPlayerEnergy returns player energy amount
     * @return energy
     * @pre -
     * @post Exception guarantee: nothrow
     */
    int getPlayerEnergy();
    /**
     * @brief increaseModifier increases score modifier by one
     * @pre -
     * @post Exception guarantee: nothrow
     */
    void increaseModifier();

private:
    int score_ = 0;
    int energy_ = 100;
    int modifier_ = 1;
};

#endif // STATISTICS_HH
