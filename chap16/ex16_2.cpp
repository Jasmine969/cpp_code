#include <iostream>
#include <cstring>
#include <string>
using std::cout;

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    return (lhs > rhs) ? 1 : -1;
}

template <unsigned N, unsigned M>
int compare(const char (&lhs)[N], const char (&rhs)[M])
{
    return std::strcmp(lhs, rhs);
}

int main()
{
    int i = 0;
    int *p1 = 0, *p2(&i);
    // cout << compare(p1, p2) << '\n';
    // cout << (p2 < p1) << '\n';
    return 0;
}