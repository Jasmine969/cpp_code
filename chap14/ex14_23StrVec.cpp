#include "StrVec_chap14.h"
#include <algorithm>
#include <iterator>

using std::copy;
using std::ostream_iterator;

int main()
{
    StrVec sv{"I", "Love"};
    ostream_iterator<string> o_it(cout, " ");
    copy(sv.begin(), sv.end(), o_it);
    cout << '\n';
    sv = {"I", "Love", "U"};
    copy(sv.begin(), sv.end(), o_it);
    return 0;
}