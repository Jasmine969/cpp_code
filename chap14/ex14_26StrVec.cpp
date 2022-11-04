#include "StrVec_chap14.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;


int main()
{
    StrVec sv{"Hello", "World"};
    sv[0] = "kao";
    cout << sv[0];
    return 0;
}