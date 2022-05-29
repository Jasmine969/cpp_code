#include <vector>
#include <iostream>
#include <iterator>
#include <list>

using std::list;
using std::vector;
using std::cout;
using std::begin;
using std::end;

int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,34,55,89};
    vector<int> vi(begin(ia), end(ia));
    list<int> li(begin(ia), end(ia));
    // list
    auto l_it = li.begin(), l_end = li.end();
    while (l_it != l_end)
    {
        if (*l_it & 1)
        {
            l_it = li.erase(l_it);
        }
        else
        {
            ++l_it;
        }
    }
    for (int i : li)
    {
        cout << i << ' ';
    }
    cout << '\n';
    // vector
    auto v_it = vi.begin(), v_end = vi.end();
    while (v_it != v_end)
    {
        if (!(*v_it & 1))
        {
            v_it = vi.erase(v_it);
        }
        else
        {
            ++v_it;
        }
    }
    for (int i : vi)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}