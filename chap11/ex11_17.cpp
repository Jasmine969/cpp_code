#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using std::inserter;
using std::back_inserter;
using std::copy;
using std::cout;
using std::multiset;
using std::string;
using std::vector;
using std::ostream_iterator;

int main()
{
    vector<string> v{"if", "I", "got"};
    multiset<string> c{"this", "innocence", "is", "brilliant"};
    ostream_iterator<string> os(cout, " ");
    // copy(v.begin(), v.end(), inserter(c, c.begin()));
    // copy(v.begin(), v.end(), back_inserter(c));
    // copy(c.begin(), c.end(), os);
    // copy(c.begin(), c.end(), inserter(v, v.end()));
    copy(c.begin(), c.end(), back_inserter(v));
    copy(v.begin(), v.end(), os);
    return 0;
}