#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>

using std::for_each;
using std::vector;
using std::list;
using std::unique_copy;
using std::back_inserter;
using std::cout;
using std::sort;

int main()
{
    vector<int> vi {1,4,2,2,3,4,5};
    sort(vi.begin(), vi.end());
    list<int> li;
    unique_copy(vi.begin(), vi.end(), back_inserter(li));
    for_each(li.begin(), li.end(),
    [] (int i) {cout << i << ' ';});
    cout << '\n';
    return 0;
}