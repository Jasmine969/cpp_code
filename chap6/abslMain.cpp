/*本文件要和absl.cpp联合编译。
也可以不在本文件中声明函数，但需要解注释#include Chapter6.h，并在Chapter6.h中添加函数声明*/
#include <iostream>
#include "Chapter6.h"
#include <iomanip>

using namespace std;
template <typename> double absl(double);
extern template double absl<char>(double);

int main()
{
    double a0 = -9.7;
    int a = a0;
    cout << fixed;
    cout << absl<char>(a) << endl;
    cout << a << endl;
    cout << a0 << endl;
    return 0;
}

