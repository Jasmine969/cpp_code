#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../myfunc.h"
#include <functional>
#include "../chap6/Chapter6.h"

using std::bind;
using namespace std::placeholders;
using std::cout;
using std::find_if;
using std::for_each;
using std::ostream;
using std::ref;
using std::stable_sort;
using std::string;
using std::vector;

bool longer(const string &s, unsigned sz)
{
    return s.size() > sz;
}

ostream &print(const string &s, ostream &os, char c)
{
    return os << s << c;
}

void biggies(vector<string> vstr, unsigned sz)
{
    // 按长度排序
    stable_sort(vstr.begin(), vstr.end(), isShorter);
    // 找到第一个长度不小于sz的下标
    vector<string>::const_iterator begin_sz = find_if(vstr.begin(), vstr.end(),
                                                      bind(longer, _1, sz));
    // 计算满足size <= sz的元素个数
    vector<string>::difference_type count = begin_sz - vstr.begin();
    cout << count << " " << makePlural(count, "word") << " of length " << sz << " or shorter." << '\n';
    // 打印所有长度不小于sz的字符串
    for_each(vstr.begin(), vstr.end(),
             bind(print, _1, ref(cout), ' '));
}
int main()
{
    vector<string> vstr{"123", "123456", "12", "1234567", "123456", "12", "12345", "123"};
    biggies(vstr, 6);
    return 0;
}