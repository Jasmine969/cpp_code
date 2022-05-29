#include <list>
#include <vector>
#include <iostream>

using std::list;
using std::vector;
using std::cout;

int main()
{
    list<int> list1{1,2,3,4};
    vector<double> dvec(list1.cbegin(),list1.cend());

    vector<int> ivec{2,3,4,5};
    vector<double> dvec2(ivec.cbegin(), ivec.cend());

    for (auto d:dvec)
    {
        cout << d << ' ';
    }
    cout << '\n';
    for (auto d2:dvec2)
    {
        cout << d2 << ' ';
    }
    cout << '\n';
    dvec2[3] = 10;
        for (auto d2:dvec2)
    {
        cout << d2 << ' ';
    }
    cout << '\n';
    return 0;
}