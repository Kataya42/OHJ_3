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
    void scoreAdditionTest();
    void modifierIncreaseTest();

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

QTEST_APPLESS_MAIN(StatisticsTest)

#include "tst_statisticstest.moc"
