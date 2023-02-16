#include <iostream>
using std::cout;

void g(int &&i1, int &i2)
{
    cout << i1 << '\t' << ++i2 << '\n';
}

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    int val1 = 2, val2 = 20;
    flip(g, val1, 42);
    return 0;
}