// 加减乘除都定义成了内联函数，所以放在了头文件里
// fvec也在头文件
#include "Chapter6.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{
    int a = 15, b = 5;
    for (unsigned int i = 0; i < 4; ++i)
    {
        cout << fvec[i](a, b) << endl;
    }
    return 0;
}