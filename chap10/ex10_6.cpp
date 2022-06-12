#include <iostream>
#include <algorithm>

using std::fill_n;
using std::cout;

int main()
{
    int a[5]{1,2,3,4,5};
    fill_n(a, 5, 0);
    for (auto i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}