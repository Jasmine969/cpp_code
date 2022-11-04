#ifndef HASPTR_DRAFT_H
#define HASPTR_DRAFT_H
#include <string>
#include <iostream>

using std::cout;
using std::string;

struct HasPtr
{
    int i;
    string *ps;
    HasPtr(const string &s = "") : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : i(hp.i), ps(new string(*hp.ps)) // 拷贝构造函数
     { cout << "copy constructor\n"; }
    HasPtr &operator=(const HasPtr &rhs) // 拷贝赋值运算符
    {
        auto p = new string(*rhs.ps);
        delete ps;
        ps = p;
        i = rhs.i;
        cout << "copy-assignment\n";
        return *this;
    }
    HasPtr(HasPtr &&hp) noexcept : i(hp.i), ps(hp.ps) // 移动构造函数
    {
        hp.ps = 0;
        cout << "move constructor\n";
    }
    HasPtr &operator=(HasPtr &&hp) noexcept // 移动赋值运算符
    {
        i = hp.i;
        ps = hp.ps;
        hp.ps = 0;
        cout << "move-assignment\n";
        return *this;
    }
};

#endif