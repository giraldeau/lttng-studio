#include <QString>
#include <QTextStream>
#include <QFile>

#include <iostream>
#include <unistd.h>
#include <sys/personality.h>
#include <sys/types.h>
#include <signal.h>
#include <ucontext.h>

#include <libunwind.h>

using namespace std;

/*
 * Registers can't be saved by the running code,
 * the code must be interrupted.
 */

class RegistersX86_64 {
public:
    enum RegsLabel {
        REG_SP = 0,
        REG_AX,
        REG_BX,
        REG_CX,
        REG_DX
    };

    unsigned long value(RegsLabel label)
    {
        register unsigned long rsp asm("rsp");
        register unsigned long rax asm("rax");
        register unsigned long rbx asm("rbx");
        register unsigned long rcx asm("rcx");
        register unsigned long rdx asm("rdx");
        switch(label) {
        case REG_SP:
            return rsp;
        case REG_AX:
            return rax;
        case REG_BX:
            return rbx;
        case REG_CX:
            return rcx;
        case REG_DX:
            return rdx;
        default:
            break;
        }
        return 0;
    }
};

class UnwindData {
public:
    UnwindData();
    void stack();
    void stack(QByteArray &array);
    void regs();
    void maps();
    QByteArray getStackData() { return stackData; }
private:
    unsigned long tos; // top of stack
    RegistersX86_64 registers;
    QByteArray stackData;
};

UnwindData::UnwindData()
{
    cout << "UnwindData" << endl;
    tos = registers.value(RegistersX86_64::REG_SP);
}

void UnwindData::stack()
{
    stack(stackData);
}

void UnwindData::stack(QByteArray &array)
{
    QTextStream out(stdout);
    unsigned long eos = registers.value(RegistersX86_64::REG_SP);
    unsigned long tos_page = (tos & (~0 << 12)) + (1 << 12);
    int size = (tos_page) - eos;
    QString str = QString("0x%1 \n0x%2 \n0x%3 \n%4 \n%5")
            .arg(tos, 0, 16)
            .arg(tos_page, 0, 16)
            .arg(eos, 0, 16)
            .arg(tos - eos, 0, 10)
            .arg(size, 0, 10);
    out << str << endl;

    array.clear();
    array.append((char *)eos, size);
}

void UnwindData::regs()
{
}

void UnwindData::maps()
{
}

class C {
public:
    void c() {
        //kill(getpid(), SIGUSR1);

    }
};

class B {
public:
    void b() {
        C *c = new C();
        c->c();
    }
};

class A {
public:
    void a() {
        volatile register unsigned int val = 0xCAFEBABE;
        (void)val;
        B *b = new B();
        b->b();
    }
};

UnwindData uw;

void trigger(int sig)
{
    uw.stack();
}

int main(int argc, char *argv[])
{
    // prevent warning about unused arguments
    (void)argc;
    (void)argv;

    /*
     * Respawn ourself without address randomization
     */
    if (argc == 1) {
        personality(ADDR_NO_RANDOMIZE);
        char *bin = argv[0];
        char **arg = new char*[2];
        arg[0] = bin;
        arg[1] = strdup("0");
        execvp(bin, (char * const *)arg);
    }

    //signal(SIGUSR1, trigger);

    A *a = new A();
    a->a();

    QFile f("stack.data");
    f.open(QIODevice::ReadWrite | QIODevice::Truncate);
    qint64 ret = f.write(uw.getStackData());
    cout << " written=" << ret << endl;
    f.close();

}
