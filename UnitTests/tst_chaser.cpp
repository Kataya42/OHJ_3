#include <QtTest>
#include "chaser.h"

// add necessary includes here

class ChaserTest : public QObject
{
    Q_OBJECT

public:
    ChaserTest();

private slots:
    void sameLocTest();
    void basicChaseTest();
    void longerChaseTest();
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
    QEXPECT_FAIL("", "Currently chaser will accelerate even if ontop of target, may change behavior in future", Continue);
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

QTEST_APPLESS_MAIN(ChaserTest)

#include "tst_chaser.moc"
