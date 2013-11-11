#include <QString>
#include <QtTest>
#include <QDebug>

#include <libunwind-x86_64.h>

#include <unwind/unwinder.h>

extern "C" {
int _find_proc_info(unw_addr_space_t, unw_word_t, unw_proc_info_t *, int, void *)
{
    qDebug() << "find_proc_info";
    return 0;
}

void _put_unwind_info(unw_addr_space_t, unw_proc_info_t *, void *)
{
    qDebug() << "put_unwind_info";
    return;
}

int _get_dyn_info_list_addr(unw_addr_space_t, unw_word_t *, void *)
{
    qDebug() << "get_dyn_info_list_addr";
    return 0;
}

int _access_mem(unw_addr_space_t, unw_word_t, unw_word_t *, int, void*)
{
    qDebug() << "access_mem";
    return 0;
}

int _access_reg(unw_addr_space_t, unw_regnum_t, unw_word_t *, int, void *)
{
    qDebug() << "access_reg";
    return 0;
}

int _access_fpreg(unw_addr_space_t, unw_regnum_t, unw_fpreg_t *, int, void *)
{
    qDebug() << "access_fpreg";
    return 0;
}

int _resume(unw_addr_space_t, unw_cursor_t *, void *)
{
    qDebug() << "resume";
    return 0;
}

int _get_proc_name(unw_addr_space_t, unw_word_t, char *, size_t, unw_word_t *, void *)
{
    qDebug() << "get_proc_name";
    return 0;
}

static unw_accessors_t myacc = {
    .find_proc_info = _find_proc_info,
    .put_unwind_info = _put_unwind_info,
    .get_dyn_info_list_addr = _get_dyn_info_list_addr,
    .access_mem = _access_mem,
    .access_reg = _access_reg,
    .access_fpreg = _access_fpreg,
    .resume = _resume,
    .get_proc_name = _get_proc_name,
};
}

class UnwindTest : public QObject
{
    Q_OBJECT

public:
    UnwindTest();

private Q_SLOTS:
    void testImportUnwind();
    void testCreateUnwind();
    void testUnwindAccessors();
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

QTEST_APPLESS_MAIN(UnwindTest)

#include "tst_unwind.moc"
