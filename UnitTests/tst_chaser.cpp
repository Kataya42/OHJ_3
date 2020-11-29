#include <QtTest>
#include <iostream>
#include <string>
#include "chaser.h"

// add necessary includes here

class ChaserTest : public QObject
{
    Q_OBJECT

public:
    ChaserTest();

private slots:
    /**
     * @brief sameLocTest Tests whether chaser will move even if target is on top of it.
     */
    void sameLocTest();
    /**
     * @brief basicChaseTest Basic test for chasing a target along one axis
     */
    void basicChaseTest();
    /**
     * @brief longerChaseTest More complicated test for chasing a target a longer distance along two axis.
     */
    void longerChaseTest();
    /**
     * @brief accelerationTest Tests whether acceleration works correctly
     */
    void accelerationTest();
    void giveLocationErrorTest();
    void moveErrorTest();
};

ChaserTest::ChaserTest()
{

}

void ChaserTest::sameLocTest()
{
    Interface::Location loc1;
    loc1.setXY(10, 10);
    Chaser testchaser;
    std::shared_ptr<Chaser> target = nullptr;
    target = std::make_shared<Chaser>();
    testchaser.move(loc1);
    target->move(loc1);
    testchaser.chase(target);
    QEXPECT_FAIL("", "Currently chaser will accelerate even if ontop of target", Continue);
    QVERIFY(testchaser.giveLocation().giveX() == loc1.giveX() and testchaser.giveLocation().giveY() == loc1.giveY());

}

void ChaserTest::basicChaseTest()
{
    Interface::Location loc1;
    loc1.setXY(10, 10);
    Chaser testchaser;
    std::shared_ptr<Chaser> target = nullptr;
    target = std::make_shared<Chaser>();
    target->move(loc1);
    loc1.setXY(30, 10);
    testchaser.move(loc1);
    testchaser.setAcceleration(10);
    testchaser.chase(target);
    QVERIFY(testchaser.isClose(target, 15));
}

void ChaserTest::longerChaseTest()
{
    Interface::Location loc1;
    loc1.setXY(0, 0);
    Chaser testchaser;
    std::shared_ptr<Chaser> target = nullptr;
    target = std::make_shared<Chaser>();
    target->move(loc1);
    loc1.setXY(100, 100);
    testchaser.move(loc1);
    testchaser.setAcceleration(10);
    testchaser.setMaxSpeed(10);
    for (int i = 0; i < 10; i++) {
        testchaser.chase(target);
    }
    QVERIFY(testchaser.isClose(target, 15));

}

void ChaserTest::accelerationTest()
{
    //first test whether chaser reaches target in correct time
    Interface::Location loc1;
    loc1.setXY(0, 0);
    Chaser testchaser;
    std::shared_ptr<Chaser> target = nullptr;
    target = std::make_shared<Chaser>();
    target->move(loc1);
    loc1.setXY(0, 10);
    testchaser.move(loc1);
    testchaser.setAcceleration(1);
    testchaser.setMaxSpeed(10);
    for (int i = 0; i < 4; i++) {
        testchaser.chase(target);
    }
    QVERIFY(testchaser.giveLocation().giveY()== 0);

    // next test if chaser decelerates and accelerates in the opposite direciton correctly.
    target->move(loc1);
    for (int i = 0; i < 7; i++) {
        testchaser.chase(target);
    }
    QVERIFY(testchaser.giveLocation().giveY()== 0);
}

void ChaserTest::giveLocationErrorTest()
{
    Chaser testchaser;
    try {
        std::string s = std::to_string(testchaser.giveLocation().giveX());
        QVERIFY(false);
    } catch (...) {
        QVERIFY(true);
    }
}

void ChaserTest::moveErrorTest()
{
    Chaser testchaser;
    Interface::Location loc1;
    try {
        testchaser.move(loc1);
        QVERIFY(false);
    } catch (...) {
        QVERIFY(true);
    }
}

QTEST_APPLESS_MAIN(ChaserTest)

#include "tst_chaser.moc"
