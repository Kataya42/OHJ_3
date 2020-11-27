#include <QtTest>
// #include "manse.h"

// add necessary includes here

class ManseTest : public QObject
{
    Q_OBJECT

public:
    ManseTest();
    ~ManseTest();

private slots:
    void test_case1();

};

ManseTest::ManseTest()
{

}

ManseTest::~ManseTest()
{

}

void ManseTest::test_case1()
{

}

QTEST_APPLESS_MAIN(ManseTest)

#include "tst_mansetest.moc"
