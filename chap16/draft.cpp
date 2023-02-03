#include <iostream>
#include <string>
#include <algorithm>
#include "Blob.h"
#include <functional>
#include <vector>
#include <iterator>
#include "../myfunc.h"
#include <memory>

using std::cout;
using std::string;
using namespace std::placeholders;
using std::back_inserter;
using std::ostream;
using std::vector;

template <typename T1, typename T2, typename T3>
T1 f(T2 i1, T3 i2)
{
    return i1 + i2;   
}

int main()
{
    double a = f<double, short>(1, 3);    
    return 0;
}