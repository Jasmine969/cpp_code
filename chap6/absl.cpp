#include <iostream>
// #include "Chapter6.h"

using namespace std;

using std::cout;
using std::endl;

template <typename T = char>
double absl(double x)
{
    double ret = x >= 0 ? x : -x;
    return ret;
}

// template double absl<char>(double x);