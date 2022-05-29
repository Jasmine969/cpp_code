#include <iostream>
#include <forward_list>

using std::cout;
using std::forward_list;

int main()
{
    forward_list<int> li{0,1,2,3,4,5,6,7,8,9};
    auto curr = li.begin(), prev = li.before_begin();
    while (curr != li.end())
    {
        if (*curr % 2)
        {
            prev = li.insert_after(curr,*curr);
            curr = prev;
            ++curr;
        }
        else
        {
            curr = li.erase_after(prev);
        }
    }
    for (auto i : li)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}