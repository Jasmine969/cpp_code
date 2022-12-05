#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../myfunc.h"

using std::cout;
using std::find_if;
using std::for_each;
using std::ostream;
using std::stable_sort;
using std::string;
using std::vector;

struct CompareStr
{
    bool operator()(const string &s1, const string &s2)
    {
        return s1 <= s2;
    }
};

class LenGE
{
    size_t sz;

public:
    LenGE(size_t i) : sz(i) {}
    bool operator()(const string &s)
    {
        return s.size() >= sz;
    }
};

class Print
{
    ostream &os;
    char sep;

public:
    Print(ostream &o=cout, char c=' ') : os(o), sep(c) {}
    void operator()(const string &s)
    {
        os << s << sep;
    }
};

void biggies(vector<string> vstr, unsigned sz)
{
    // 按长度排序
    stable_sort(vstr.begin(), vstr.end(), CompareStr());
    // 找到第一个长度不小于sz的下标
    vector<string>::const_iterator
        begin_5 = find_if(vstr.begin(), vstr.end(), LenGE(5));
    // 计算满足size >= sz的元素个数
    vector<string>::difference_type count = vstr.end() - begin_5;
    cout << count << " " << makePlural(count, "word") << " of length " << sz << " or longer." << '\n';
    // 打印所有长度不小于sz的字符串
    for_each(begin_5, vstr.cend(), Print());
}
int main()
{
    vector<string> vstr{"123", "123456", "12", "1234567", "123456", "12", "12345", "123"};
    biggies(vstr, 5);
    return 0;
}