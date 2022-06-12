#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "../myfunc.h"
#include <deque>

using std::deque;
using std::back_inserter;
using std::inserter;
using std::front_inserter;
using std::cout;
using std::for_each;
using std::copy;
using std::vector;
using std::ostream_iterator;

int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    vector<int> v1, v2;
    deque<int> d3;   
    copy(vi.begin(), vi.end(), back_inserter(v1));
    copy(vi.begin(), vi.end(), inserter(v2, v2.begin()));
    copy(vi.begin(), vi.end(), front_inserter(d3));
    printVec(v1);
    printVec(v2);
    for_each(d3.begin(), d3.end(), [] (int i) {cout << i << ' ';});
    copy(d3.begin(), d3.end(), ostream_iterator<int>(cout, " "));
    return 0;
}