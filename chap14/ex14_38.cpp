#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <set>

using std::count_if;
using std::cout;
using std::ifstream;
using std::istream_iterator;
using std::string;
using std::vector;

class StrSize
{
    size_t sz;

public:
    StrSize(size_t i) : sz(i) {}
    bool operator()(const string &s)
    {
        return s.size() == sz;
    }
};

int main()
{
    ifstream in("lyrics2.txt");
    istream_iterator<string> in_it(in), eof;
    vector<string> svec(in_it, eof);
    for (size_t len = 1; len != 11; ++len)
    {
        unsigned cnt = count_if(svec.begin(), svec.end(), StrSize(len));
        cout << "长度为" << len << "的单词有" << cnt << "个\n";
    }
    return 0;
}