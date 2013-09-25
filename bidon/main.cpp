#include <iostream>
#include <ucontext.h>
#include <QString>
#include <QTextStream>

using namespace std;

int g = 42;

int main()
{
    QTextStream out(stdout);
    register long long int r = 42;
    int i = 42;
    ucontext_t ucp;
    getcontext(&ucp);
    out << QString("global=%1 register=%2 stack=%3\n")
           .arg(g++).arg(r++).arg(i++) << endl;
    if (g < 43 + 3)
        setcontext(&ucp);
    cout << ucp.uc_stack.ss_sp << endl;
    cout << ucp.uc_stack.ss_flags << endl;
    cout << ucp.uc_stack.ss_size / (1024 * 1024) << endl;
    for (int x = 0; x < NGREG; x++)
        cout << ucp.uc_mcontext.gregs[x] << endl;

    cout << "Done" << endl;
    return 0;
}

