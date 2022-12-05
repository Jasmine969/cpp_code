#include <map>
#include <functional>
#include <iostream>
#include <string>

using std::cout;
using std::map;
using std::minus;
using std::function;
using std::string;

int add(int lhs, int rhs)
{
    return lhs + rhs;
}

struct divide
{
    int operator()(int lhs, int rhs)
    {
        return lhs / rhs;
    }
};

int main()
{
    map<string, function<int(int, int)>> binops
    {
        {"+", add},
        {"-", minus<int>()},
        {"*", [](int lhs, int rhs) { return lhs * rhs; }},
        {"/", divide()},
        {"%", [](int lhs, int rhs) { return lhs % rhs; }}
    };
    cout << binops["+"](10,5) << '\n';
    cout << binops["-"](10,5) << '\n';
    cout << binops["*"](10,5) << '\n';
    cout << binops["/"](10,5) << '\n';
    cout << binops["%"](10,5) << '\n';
    return 0;
}