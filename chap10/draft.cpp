#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "../myfunc.h"
#include <iterator>
#include "../chap6/Chapter6.h"
#include <functional>

using std::back_inserter;
using std::inserter;
using std::cout;
using std::fill_n;
using std::find;
using std::find_if;
using std::partition;
using std::replace_copy;
using std::sort;
using std::stable_sort;
using std::string;
using std::transform;
using std::unique;
using std::vector;
using namespace std::placeholders;
using std::for_each;
using std::ostream;
using std::ref;
using std::bind;
using std::boolalpha;
using std::istream_iterator;
using std::cin;

bool less(double d1, double d2)
{
    return d1 < d2;
}

ostream &print(ostream &os, double d)
{
    return os << d << ' ';
}
int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vi(in_iter, eof);
    printVec(vi);
    return 0;
}