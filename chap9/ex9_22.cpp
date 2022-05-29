#include <vector>
#include <iostream>

using std::cout;
using std::vector;

int main()
{
    vector<int> ivec{1, 2, 1, 3, 1, 5, 3, 4, 1, 9};
    vector<int>::iterator iter = ivec.begin(),
                          mid = ivec.begin() + ivec.size() / 2;
    cout << *mid << '\n';
    while (iter != mid)
    {
        if (*iter == 1)
        {
            auto distance = mid - iter;
            iter = ivec.insert(iter, 20);
            mid = iter + distance + 1;
            iter += 2;
        }
        else
        {
            ++iter;
        }
        for (auto i : ivec)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    for (auto i : ivec)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}