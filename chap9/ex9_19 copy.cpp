#include <list>
#include <iostream>
#include <deque>

using std::cout;
using std::deque;
using std::list;

int main()
{
    std::ios::sync_with_stdio(false);
    list<int> lint{1, 2, 3, 4, 5, 6, 7};
    deque<int> di_odd;
    deque<int> di_even;
    for (int i : lint)
    {
        if (i % 2)
        {
            di_odd.push_back(i);
        }
        else
        {
            di_even.push_back(i);
        }
    }
    cout << "Odd:";
    for (auto i : di_odd)
    {
        cout << ' ' << i;
    }
    cout << "\nEven:";
    for (auto i : di_even)
    {
        cout << ' ' << i;
    }
    cout << '\n';
    return 0;
}