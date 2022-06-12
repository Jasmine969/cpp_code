#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../myfunc.h"

using std::cout;
using std::find_if;
using std::for_each;
using std::stable_sort;
using std::string;
using std::vector;

void biggies(vector<string> vstr, unsigned sz)
{
    // 按长度排序
    stable_sort(vstr.begin(), vstr.end(),
                [](const string &s1, const string &s2)
                { return s1 <= s2; });
    // 找到第一个长度不小于sz的下标
    vector<string>::const_iterator begin_5 = find_if(vstr.begin(), vstr.end(),
            [sz](const string &s)
            { return s.size() >= 5; });
    // 计算满足size >= sz的元素个数
    vector<string>::difference_type count = vstr.end()-begin_5;
    cout << count <<" "<< makePlural(count, "word") << " of length " << sz << " or longer."<<'\n';
    // 打印所有长度不小于sz的字符串
    for_each(begin_5, vstr.cend(),
             [](const string &s)
             { cout << s << ' '; });
}
int main()
{
    vector<string> vstr{"123", "123456", "12", "1234567", "123456", "12", "12345", "123"};
    biggies(vstr, 5);
    return 0;
}