#include <list>
#include <iostream>
#include <algorithm>
#include <vector>

using std::list;
using std::cout;
using std::find;
using std::vector;

int main()
{
    list<int> li{1,0,2,30,0,4,5,0,0,11,9};
    auto last0 = find(li.crbegin(), li.crend(), 0);
    list<int> li2(li.cbegin(), last0.base());
    cout << li2.size() << " numbers from the start.\n";
    return 0;
}