#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int a[10] = {};
    for (int i = 0; i < 10; ++i)
        a[i] = i;
    for (auto i : a)
        cout << i << ' ';
    cout << endl;
    // ex3_32
    int b[10]{};
    for (int i = 0; i < 10; ++i)
        b[i] = a[i];
    for (auto j : b)
        cout << j << ' ';
    cout << endl;
    return 0;
}