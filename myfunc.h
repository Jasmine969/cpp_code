#ifndef MYFUNC_H
#define MYFUNC_H

#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::vector;
using std::pow;
using std::round;

inline double myRound(double x, int digit)
// 保留小数到小数点后指定位数
{
    return (round(x * pow(10, digit) + 0.0) / pow(10, digit));
}

void printVec(const vector<int>& v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void printVec(const vector<unsigned>& v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void printVec(const vector<double>& v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void printVec(const vector<string>& v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void printVec(const vector<char>& v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

void printVec(const vector<const char*>& v)
{
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

// 如果需要（个数>1）变单词为复数形式
string makePlural(unsigned cnt, string s, const string& ending="s")
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
#endif