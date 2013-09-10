#include <QString>
#include <QtTest>
#include <AutoTest.h>

#include <core.h>

class TestBasic : public QObject
{
    Q_OBJECT
    
public:
    TestBasic();
    
private Q_SLOTS:
    void testImportCore();
};

TestBasic::TestBasic()
{
}

void TestBasic::testImportCore()
{
    Core *core = new Core();
    QVERIFY2(core, "Failure");
    delete core;
}

DECLARE_TEST(TestBasic)

#include "TestBasic.moc"
