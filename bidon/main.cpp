#include <iostream>
#include <ucontext.h>
#include <string.h>

using namespace std;

int g = 0;

int main()
{
    ucontext_t ucp;
    register long long int r = 0;
    int i = 0;
    int buf[10];
    memset(buf, 0, sizeof(buf));
    getcontext(&ucp);
    cout << "global=" << g
         << " register=" << r
         << " stack=" << i
         << " buf[0]=" << buf[0]
         << endl;
    g++; r++; i++;
    for (int x = 0; x < 10; x++)
        buf[x] = g;
    if (g < 3)
        setcontext(&ucp);
    cout << "Done" << endl;
    return 0;
}

