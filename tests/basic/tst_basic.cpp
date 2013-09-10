#include <QString>
#include <QtTest>

#include <core.h>

class tst_Basic : public QObject
{
    Q_OBJECT
    
public:
    tst_Basic();
    
private Q_SLOTS:
    void testImportCore();
};

tst_Basic::tst_Basic()
{
}

void tst_Basic::testImportCore()
{
    Core *core = new Core();
    QVERIFY2(core, "Failure");
    delete core;
}

QTEST_MAIN(tst_Basic)

#include "tst_basic.moc"
