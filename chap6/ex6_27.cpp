#include <iostream>
#include <initializer_list>
#include <vector>

using std::initializer_list;
using std::endl;
using std::cout;
using std::vector;

int mySum(initializer_list<int> i1)
{
    int s = 0;
    for (auto beg = i1.begin(); beg != i1.end(); ++beg)
    {
        s += *beg;
    }
    for (auto n : i1)
    {
        cout << n << endl;
    }
    return s;
}

int main()
{
    cout << mySum({1,2,3,4,5}) << endl;
    int a[5] = {1,2,3,4,5};
    vector<int> ivec{1,2,3,4,5};
    return 0;
}