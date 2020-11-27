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


QTEST_APPLESS_MAIN(ManseTest)

#include "tst_mansetest.moc"
