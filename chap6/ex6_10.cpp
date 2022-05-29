#include <iostream>

using std::cout;
using std::endl;

void mySwap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int x = 1, y = 2, z = 3;
    mySwap(&x, &y);
    cout << x << ' ' << y << ' ' << z << endl;
    mySwap(&x, &z);
    cout << x << ' ' << y << ' ' << z << endl;
    return 0;
}