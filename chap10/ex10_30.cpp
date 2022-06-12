#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cin;
using std::copy;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::vector;
int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vi(in_iter, eof);
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));
    return 0;
}