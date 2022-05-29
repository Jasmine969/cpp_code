#include <iostream>
#include "Chapter6.h"
#include <iomanip>

using namespace std;

int main()
{
    double a0 = -9.7;
    int a = a0;
    cout << fixed;
    cout << absl(a) << endl;
    cout << a << endl;
    cout << a0 << endl;
    return 0;
}

