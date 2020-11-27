#include <QtTest>
#include "chaser.h"

// add necessary includes here

class ChaserTest : public QObject
{
    Q_OBJECT

public:
    ChaserTest();

private slots:
    void test_case1();

};

ChaserTest::ChaserTest()
{

}

void ChaserTest::test_case1()
{
    Interface::Location loc1;
    Interface::Location loc2;
}

QTEST_APPLESS_MAIN(ChaserTest)

#include "tst_chaser.moc"
