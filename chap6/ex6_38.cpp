#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int odd[5] = {1, 3, 5, 7, 9};
int even[5] = {2, 4, 6, 8, 10};
decltype(odd) &arrRef(int i)
{
    return (i % 2) ? odd : even;
}

int main()
{
    auto &ar = arrRef(1); // 注意一定要有&
    for (auto n : ar)
        cout << n << ' ';
    cout << endl;
    for (auto n : odd)
        cout << n << ' ';
    cout << endl;
    return 0;
}