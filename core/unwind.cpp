#include "unwind.h"

Unwind::Unwind()
{
    accessors.access_mem = Unwind::accessMem;
}

QStringList Unwind::callStack()
{
    return QStringList() << "a" << "b" << "c" << "main";
}

int Unwind::accessMem(unw_addr_space_t as,
              unw_word_t addr, unw_word_t *valp,
              int __write, void *arg)
{
    UNUSED(as);
    UNUSED(addr);
    UNUSED(valp);
    UNUSED(__write);
    UNUSED(arg);
    return 0;

}
