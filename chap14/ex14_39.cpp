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

class StrSizeBetween
{
    size_t min_sz, max_sz;

public:
    StrSizeBetween(size_t i, size_t j) : min_sz(i), max_sz(j) {}
    bool operator()(const string &s)
    {
        return s.size() >= min_sz && s.size() <= max_sz;
    }
};

class StrSizeGT
{
    size_t min_sz, max_sz;

public:
    StrSizeGT(size_t i) : min_sz(i) {}
    bool operator()(const string &s)
    {
        return s.size() > min_sz;
    }
};

int main()
{
    ifstream in("lyrics2.txt");
    istream_iterator<string> in_it(in), eof;
    vector<string> svec(in_it, eof);
    unsigned cnt = count_if(svec.begin(), svec.end(), StrSizeBetween(1, 9));
    cout << "长度在1至9的单词有" << cnt << "个\n";
    cnt = count_if(svec.begin(), svec.end(), StrSizeGT(10));
    cout << "长度超过10的单词有" << cnt << "个\n";
    return 0;
}