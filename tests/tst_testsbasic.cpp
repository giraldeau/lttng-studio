#include <QString>
#include <QtTest>

#include "core.h"

class TestsTest : public QObject
{
    Q_OBJECT
    
public:
    TestsTest();
    
private Q_SLOTS:
    void testImportCore();
};

TestsTest::TestsTest()
{
}

void TestsTest::testImportCore()
{
    Core *core = new Core();
    QVERIFY2(core, "Failure");
    delete core;
}

QTEST_APPLESS_MAIN(TestsTest)

#include "tst_testsbasic.moc"
