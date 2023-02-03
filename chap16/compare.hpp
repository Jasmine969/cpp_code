#ifndef COMPARE_HPP
#define COMPARE_HPP

#include <iostream>
using std::cout;

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    return (lhs > rhs) ? 1 : -1;
}

#endif