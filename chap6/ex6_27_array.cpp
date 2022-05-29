#include <iostream>

using std::initializer_list;
using std::endl;
using std::cout;

int mySum(const int p[], unsigned int sz)
{
    int s = 0;
    for (int i = 0; i != sz; ++i)
    {
        s += p[i];
    }
    return s;
}

int main()
{
    int a[5] = {1,2,3,4,5};
    return 0;
}