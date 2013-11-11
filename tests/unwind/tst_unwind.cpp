#include <QString>
#include <QtTest>
#include <QDebug>

#include <libunwind-x86_64.h>
#include <unwind/unw_wrapper.h>
#include <unwind/unwinder.h>

class UnwindTest : public QObject
{
    Q_OBJECT

public:
    UnwindTest();

private Q_SLOTS:
    void testImportUnwind();
    void testCreateUnwind();
    void testUnwindAccessors();
    void testAccessReg();
    void init();
    void cleanup();

private:
    unw_addr_space_t as;
    unw_cursor_t cursor;
    unsigned long foo;

};

UnwindTest::UnwindTest() :
    foo(0xCAFEBABECAFEBABE)
{
}

void UnwindTest::init()
{
    as = unw_create_addr_space(&myacc, 0);
    unw_init_remote(&cursor, as, &foo);
}

void UnwindTest::cleanup()
{
    unw_destroy_addr_space(as);
}

void UnwindTest::testImportUnwind()
{
    unw_accessors_t ac;
    unw_addr_space_t as = unw_create_addr_space(&ac, 0);
    QVERIFY2(as, "unw_create_addr_space() failed");
    unw_destroy_addr_space(as);
}

void UnwindTest::testCreateUnwind()
{
    Unwinder u;
}

void UnwindTest::testUnwindAccessors()
{
    unw_cursor_t cursor;
    unw_addr_space_t as;
    int ret;

    as = unw_create_addr_space(&myacc, 0);
    ret = unw_init_remote(&cursor, as, NULL);
    QVERIFY2(ret == 0, "unw_init_remote() failed");
    unw_destroy_addr_space(as);
}

void  UnwindTest::testAccessReg()
{
    unw_word_t ip;
    int ret;
    ret = unw_get_reg(&cursor, UNW_REG_IP, &ip);
    QVERIFY2(ret == 0, "unw_get_reg() failed");
}

QTEST_APPLESS_MAIN(UnwindTest)

#include "tst_unwind.moc"
