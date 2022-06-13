#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::vector;
using std::ostream_iterator;
using std::cout;
using std::copy;

int main()
{
    vector<int> vi{1,2,3,4,5};
    copy(vi.crbegin(), vi.crend(), ostream_iterator<int>(cout, " "));        
    return 0;
}