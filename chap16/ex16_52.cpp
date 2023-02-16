#include <iostream>
using std::cout;
#include <string>
using std::string;

template <typename T, typename... Args>
void foo(const T &, const Args &...args)
{
    cout << "Args:\t" << sizeof...(Args) << '\n';
    cout << "args:\t" << sizeof...(args) << '\n';
}

int main()
{
    int i = 0;
    double d = 3.14;
    string s("how now brown cow");
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
    foo(i, d, d);
    return 0;
}