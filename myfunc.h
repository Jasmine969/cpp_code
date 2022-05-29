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
#endif