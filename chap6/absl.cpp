#include <iostream>
#include "Chapter6.h"

using namespace std;

using std::cout;
using std::endl;

double absl(double x)
{
    double ret = x >= 0 ? x : -x;
    return ret;
}
