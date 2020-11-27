#include <QtTest>
#include "statistics.hh"

// add necessary includes here

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();
    ~StatisticsTest();

private slots:
    /**
     * @brief scoreAdditionTest a simple test to see whether score addition works correctly
     */
    void scoreAdditionTest();
    /**
     * @brief modifierIncreaseTest tests whether increasing the score modifier works
     */
    void modifierIncreaseTest();
    /**
     * @brief energyTest tests whether energy can be increased to over 100
     */
    void energyTest();

};

StatisticsTest::StatisticsTest()
{

}

StatisticsTest::~StatisticsTest()
{

}

void StatisticsTest::scoreAdditionTest()
{
    Statistics scoretracker;
    for (int i = 0; i < 10; i++)
    {
        scoretracker.addScore();
    }
    QVERIFY(scoretracker.getScore() == 10);

}

void StatisticsTest::modifierIncreaseTest()
{
    Statistics scoretracker;
    scoretracker.increaseModifier();
    for (int i = 0; i < 10; i++)
    {
        scoretracker.addScore();
    }
    QVERIFY(scoretracker.getScore() == 20);

}

void StatisticsTest::energyTest()
{
    Statistics scoretracker;
    for (int i = 0; i < 9; i++)
    {
        scoretracker.drainPlayerEnergy();
        scoretracker.addPlayerEnergy();
    }
    QVERIFY(scoretracker.getPlayerEnergy() == 91);
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "tst_statisticstest.moc"
