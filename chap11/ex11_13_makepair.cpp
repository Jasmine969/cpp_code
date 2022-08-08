#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::pair;
using std::string;
using std::transform;
using std::vector;
using std::back_inserter;
using std::make_pair;

// 取string序列和int序列中较短的长度作为结果序列的长度
int main()
{
    cout << "Enter the sequence of string: ";
    vector<string> vstr;
    string s;
    while (cin >> s)
    {
        vstr.push_back(s);
    }
    int i;
    cout << "Enter the sequence of int: ";
    vector<int> vint;
    cin.clear();
    while (cin >> i)
    {
        vint.push_back(i);
    }
    vector<pair<string, int>> res;
    if (vstr.size() <= vint.size())
    {
        transform(vstr.begin(), vstr.end(), vint.begin(), back_inserter(res),
        [] (string s, int i) {return make_pair(s, i);});
    }
    else
    {
        transform(vint.begin(), vint.end(), vstr.begin(), back_inserter(res),
        [] (int i, string s) {return make_pair(s, i);});
    }
    for (auto item : res)
    {
        cout << item.first << '\t' << item.second << '\n';
    }
    return 0;
}