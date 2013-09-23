#include <QString>
#include <QtTest>

#include <libunwind-x86_64.h>

class UnwindTest : public QObject
{
    Q_OBJECT

public:
    UnwindTest();

private Q_SLOTS:
    void testImportUnwind();
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

QTEST_APPLESS_MAIN(UnwindTest)

#include "tst_unwind.moc"
