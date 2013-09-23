#include <QString>
#include <QtTest>

#include <libunwind-x86_64.h>
#include <unwind.h>

class UnwindTest : public QObject
{
    Q_OBJECT

public:
    UnwindTest();

private Q_SLOTS:
    void testImportUnwind();
    void testUnwindOffline();
};

UnwindTest::UnwindTest()
{
}

void UnwindTest::testImportUnwind()
{
    unw_accessors_t ac;
    unw_addr_space_t as = unw_create_addr_space(&ac, 0);
    QVERIFY2(as, "unw_create_addr_space() failed");
    unw_destroy_addr_space(as);
}

void UnwindTest::testUnwindOffline()
{
    Unwind uw;
    QStringList exp = QStringList() << "a" << "b" << "c" << "main";
    QStringList list = uw.callStack();
    QCOMPARE(exp, list);
}

QTEST_APPLESS_MAIN(UnwindTest)

#include "tst_unwind.moc"
