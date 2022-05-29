#include <iostream>

using std::cout;
using std::endl;

void swapPointer(int *&pa, int *&pb)
{
    int *tmp = pa;
    pa = pb;
    pb = tmp;
}

int main()
{
    int a = 1, b = 2;
    int *p = &a, *q = &b;
    cout << *p << ' ' << *q << endl;
    swapPointer(p, q);
    cout << *p << ' ' << *q << endl;
    return 0;
}