#ifndef MYFUNC_H
#define MYFUNC_H

#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::cout;
using std::find_if;
using std::ispunct;
using std::pow;
using std::round;
using std::string;
using std::vector;

inline double myRound(double x, int digit)
// 保留小数到小数点后指定位数
{
    return (round(x * pow(10, digit) + 0.0) / pow(10, digit));
}

template <typename C>
void printContainer(C &container, char sep = ' ')
{
    for (auto i : container)
    {
        cout << i << sep;
    }
    cout << '\n';
}

// 如果需要（个数>1）变单词为复数形式
string makePlural(unsigned cnt, string s, const string &ending = "s")
{
    if (cnt == 1)
    {
        return s;
    }
    if (s[s.size() - 1] == 'y' && ending == "ies")
    {
        s.replace(s.size() - 1, 1, ending);
        return s;
    }
    return s + ending;
}

void remove_punct(string &word) // 去掉一个单词末尾的标点符号
{
    auto pos = find_if(word.rbegin(), word.rend(), [](char c)
                       { return !ispunct(c); });
    word.erase(pos.base(), word.end());
}

#endif