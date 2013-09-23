#ifndef UNWIND_H
#define UNWIND_H

#include <QStringList>
#include <libunwind-x86_64.h>

// FIXME: move UNUSED define in more convenient place
#define UNUSED(x) (void)(x)

class Unwind
{
public:
    Unwind();
    QStringList callStack();
private:
    unw_accessors_t accessors;
    int findProcInfo();
    int putUnwindInfo();
    int getDynInfoListAddr();
    static int accessMem(unw_addr_space_t as,
                  unw_word_t addr, unw_word_t *valp,
                  int __write, void *arg);
    int accessReg();
    int accessFPReg();
    int resume();
    int getProcName();
};


#endif // UNWIND_H
