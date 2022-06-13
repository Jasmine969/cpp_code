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
    list<int> li{1,0,2,30,0,4,5,1,0,11,9};
    auto last0 = find(li.crbegin(), li.crend(), 0);
    cout << *last0 << '\n';
    last0++;
    cout << *last0 << '\n';
    int p = 1;
    for (auto iter = li.begin(); iter != last0.base(); iter++, p++);
    cout << p << "个位置\n";
    return 0;
}