#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "../myfunc.h"
#include <iterator>
#include "../chap6/Chapter6.h"
#include <functional>
#include <list>

using std::back_inserter;
using std::cout;
using std::fill_n;
using std::find;
using std::find_if;
using std::inserter;
using std::partition;
using std::replace_copy;
using std::sort;
using std::stable_sort;
using std::string;
using std::transform;
using std::unique;
using std::vector;
using namespace std::placeholders;
using std::bind;
using std::boolalpha;
using std::cin;
using std::for_each;
using std::istream_iterator;
using std::ostream;
using std::ref;
using std::list;

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
    const vector<int> vi{1,2,3,4};
    const auto iter_c = vi.begin();
    cout << *(++iter_c) << "\n";
    return 0;
}