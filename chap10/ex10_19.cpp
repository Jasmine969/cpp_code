#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "../myfunc.h"

using std::cout;
using std::for_each;
using std::stable_partition;
using std::string;
using std::vector;

void bigges(vector<string> vstr, vector<string>::size_type sz)
{
    auto f = [sz](const string &s)
    { return s.size() >= sz; };
    auto end_5 = stable_partition(vstr.begin(), vstr.end(), f);
    // 计算满足size >= sz的元素个数
    vector<string>::difference_type count = end_5 - vstr.begin();
    cout << count << " " << makePlural(count, "word") << " of length " << sz << " or longer." << '\n';
    for_each(vstr.begin(), end_5, [](const string &s)
             { cout << s << ' '; });
}

int main()
{
    vector<string> v{"123", "12345a", "12", "1234567", "123456", "12", "12345", "123"};
    bigges(v, 5);
    return 0;
}