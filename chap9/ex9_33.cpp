#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using std::cout;
using std::vector;
using std::list;
using std::find;

int main()
{
    vector<int> v{1,2,3,4,5};
    auto begin = v.begin();
    while (begin != v.end())
    {
        begin++;
        v.insert(begin, 42);
        begin++;
    }
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}