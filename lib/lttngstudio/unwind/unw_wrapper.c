#include <stdio.h>
#include <stdlib.h>
#include <libunwind-x86_64.h>

int _find_proc_info(unw_addr_space_t as, unw_word_t val, unw_proc_info_t *pi, int _write, void *arg)
{
    (void) as;
    (void) val;
    (void) pi;
    (void) _write;
    (void) arg;
//    qDebug() << "find_proc_info";
    return 0;
}

void _put_unwind_info(unw_addr_space_t as, unw_proc_info_t *pi, void *arg)
{
    (void) as;
    (void) pi;
    (void) arg;
//    qDebug() << "put_unwind_info";
    return;
}

int _get_dyn_info_list_addr(unw_addr_space_t as, unw_word_t *valp, void *arg)
{
    (void) as;
    (void) valp;
    (void) arg;
//    qDebug() << "get_dyn_info_list_addr";
    return 0;
}

int _access_mem(unw_addr_space_t as, unw_word_t val, unw_word_t *valp, int _write, void *arg)
{
    (void) as;
    (void) val;
    (void) valp;
    (void) _write;
    (void) arg;
//    qDebug() << "access_mem";
    return 0;
}

int _access_reg(unw_addr_space_t as, unw_regnum_t regnum, unw_word_t *valp,
                int _write, void *arg)
{
    (void) as;
    (void) regnum;
    (void) valp;
    (void) _write;
    (void) arg;


    unsigned long *val = (unsigned long *) arg;

    if (val != NULL) {
        printf("access_reg 0x%lX\n", *val);
        printf("access_reg %s\n", unw_regname(regnum));
    }
    return 0;
}

int _access_fpreg(unw_addr_space_t as, unw_regnum_t regnum, unw_fpreg_t *valp,
                  int _write, void *arg)
{
    (void) as;
    (void) regnum;
    (void) valp;
    (void) _write;
    (void) arg;
//    qDebug() << "access_fpreg";
    return 0;
}

int _resume(unw_addr_space_t as, unw_cursor_t *cursor, void *arg)
{
    (void) as;
    (void) cursor;
    (void) arg;
//    qDebug() << "resume";
    return 0;
}

int _get_proc_name(unw_addr_space_t as, unw_word_t val, char *buf, size_t size, unw_word_t *valp, void *arg)
{
    (void) as;
    (void) val;
    (void) buf;
    (void) size;
    (void) valp;
    (void) arg;
//    qDebug() << "get_proc_name";
    return 0;
}

unw_accessors_t myacc = {
    .find_proc_info = _find_proc_info,
    .put_unwind_info = _put_unwind_info,
    .get_dyn_info_list_addr = _get_dyn_info_list_addr,
    .access_mem = _access_mem,
    .access_reg = _access_reg,
    .access_fpreg = _access_fpreg,
    .resume = _resume,
    .get_proc_name = _get_proc_name,
};
