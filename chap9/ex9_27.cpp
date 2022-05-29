#include <vector>
#include <iostream>
#include <iterator>
#include <forward_list>

using std::forward_list;
using std::vector;
using std::cout;
using std::begin;
using std::end;

int main()
{
    forward_list<int> li = {0,1,1,2,3,5,8,13,21,34,55,89};
    // list
    auto l_it = li.cbegin(), prev = li.cbefore_begin();
    while (l_it != li.cend())
    {
        if (*l_it & 1)
        {
            l_it = li.erase_after(prev);
        }
        else
        {
            ++l_it;
            ++prev;
        }
    }
    for (int i : li)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}