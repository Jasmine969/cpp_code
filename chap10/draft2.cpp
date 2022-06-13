#include <vector>
#include <iostream>

using std::cout;
using std::vector;

int main()
{
    vector<int> vi{1,2,3,4,5};
    auto iter = vi.rbegin() + 1;
    auto iter_base = iter.base();
    vector<int>::reverse_iterator riter(iter_base);
    cout << *iter << ' ' << *iter_base << ' ' << *riter << '\n';
    return 0;
}