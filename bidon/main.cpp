#include <iostream>
#include <ucontext.h>
#include <string.h>

using namespace std;

int g = 0;

int main()
{
    ucontext_t ucp;
    register long long int r asm("r10") = 42;
    int i = 0;
    int buf[10];
    memset(buf, 0, sizeof(buf));
    getcontext(&ucp);
    cout << "global=" << g
         << " register=" << r
         << " stack=" << i
         << endl;

    g++; r++; i++;
    for (int x = 0; x < 10; x++)
        cout << buf[x] << endl;
    for (int x = 0; x < 10; x++)
        buf[x] = x + g + r + i;
    for (int x = 0; x < 10; x++)
        cout << buf[x] << endl;
    if (g < 3)
        setcontext(&ucp);
    for (int x = 0; x < 10; x++)
        cout << buf[x] << endl;
    cout << "Done" << endl;
    return 0;
}

