#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "../myfunc.h"
#include <functional>

using std::bind;
using namespace std::placeholders;
using std::cout;
using std::for_each;
using std::partition;
using std::string;
using std::vector;
using std::ostream;

bool checkSize(const string& s, string::size_type sz)
{
    return s.size() >= sz;
}

ostream &print(const string &s, ostream &os, char c)
{
    return os << s << c;
}

void bigges(vector<string> vstr, string::size_type sz)
{
    auto end_5 = partition(vstr.begin(), vstr.end(),
    bind(checkSize, _1, sz));
    // 计算满足size >= sz的元素个数
    vector<string>::difference_type count = end_5 - vstr.begin();
    cout << count << " " << makePlural(count, "word") << " of length " << sz << " or longer." << '\n';
    for_each(vstr.begin(), end_5,
    bind(print, _1, ref(cout), ' '));
}

int main()
{
    vector<string> v{"123", "12345a", "12", "1234567", "123456", "12", "12345", "123"};
    bigges(v, 5);
    return 0;
}