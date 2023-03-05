#ifndef PRINT_EX53_H
#define PRINT_EX53_H

#include <iostream>

template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t << '\n';
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &...rest)
{
    os << t << ", ";
    return print(os, rest...);
}

#endif