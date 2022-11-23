#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>

using std::cout;
using std::deque;
using std::replace_if;
using std::ostream_iterator;
using std::copy;

class IsEqual
{
    int i;
    public:
    IsEqual(int val=0): i(val) {}
    bool operator()(int j)
    {
        return i == j;
    }
};

int main()
{
    deque<int> dint{1,2,3,4,5,6,3,4,5};
    replace_if(dint.begin(), dint.end(), IsEqual(4), 40);
    ostream_iterator<int> oit(cout, " ");
    copy(dint.begin(), dint.end(), oit);
    return 0;
}