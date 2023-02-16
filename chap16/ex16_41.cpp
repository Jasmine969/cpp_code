#include <iostream>
using std::cout;

template <typename T1, typename T2>
auto sum(T1 v1, T2 v2) -> decltype(v1 + v2)
{
    return v1 + v2;
}

int main()
{
    unsigned short a = 65535;
    cout << a << '\t' << sum(a, a) << '\n';
    // cout << sum(1111111111111,11111111111111111) << '\n';
    return 0;
}