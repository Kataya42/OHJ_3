#include <QtTest>
#include "manse.h"
#include "player.h"

// add necessary includes here

class ManseTest : public QObject
{
    Q_OBJECT

public:
    ManseTest();
    ~ManseTest();

private slots:
    /**
     * @brief findActorTest Tests whether findActor works correctly in simple situations
     */
    void findActorTest();
    /**
     * @brief removeActorTest Tests whether removeActor works correctly
     */
    void removeActorTest();
    /**
     * @brief getNearbyActorsTest Tests whether getNearbyActors works correctly
     */
    void getNearbyActorsTest();

};

ManseTest::ManseTest()
{

}

ManseTest::~ManseTest()
{

}

void ManseTest::findActorTest()
{
    Manse testmanse;
    std::shared_ptr<Player> testactor1 = nullptr;
    testactor1 = std::make_shared<Player>();
    std::shared_ptr<Player> testactor2 = nullptr;
    testactor2 = std::make_shared<Player>();
    std::shared_ptr<Player> testactor3 = nullptr;
    testactor3 = std::make_shared<Player>();
    testmanse.addActor(testactor1);
    testmanse.addActor(testactor2);
    QVERIFY(testmanse.findActor(testactor2));
    QVERIFY(not testmanse.findActor(testactor3));
}

void ManseTest::removeActorTest()
{
    Manse testmanse;
    std::shared_ptr<Player> testactor1 = nullptr;
    testactor1 = std::make_shared<Player>();
    testmanse.addActor(testactor1);
    testmanse.removeActor(testactor1);
    QVERIFY(testactor1->isRemoved());
}

void ManseTest::getNearbyActorsTest()
{
    //Adds 3 actors at distances of 0, 5 and 20, and then searches for nearby ones at the first ones location
    Manse testmanse;
    Interface::Location testloc;
    testloc.setXY(-350, 550);
    std::shared_ptr<Player> testactor1 = nullptr;
    testactor1 = std::make_shared<Player>();
    testactor1->move(testloc);
    testmanse.addActor(testactor1);

    testloc.setXY(-350, 555);
    std::shared_ptr<Player> testactor2 = nullptr;
    testactor2 = std::make_shared<Player>();
    testactor2->move(testloc);
    testmanse.addActor(testactor2);

    testloc.setXY(-350, 570);
    std::shared_ptr<Player> testactor3 = nullptr;
    testactor3 = std::make_shared<Player>();
    testactor3->move(testloc);
    testmanse.addActor(testactor3);

    //Converting from buscoordinates to screencoordinates
    testloc.setXY(0,0);
    QVERIFY(testmanse.getNearbyActors(testloc).size() == 2);
    QVERIFY(testmanse.getNearbyActors(testloc).at(0) == testactor1);
}


QTEST_APPLESS_MAIN(ManseTest)

#include "tst_mansetest.moc"
