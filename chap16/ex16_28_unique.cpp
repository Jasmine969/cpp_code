#include "uniquePtr.h"
// #include "UP_CSAN.h"
#include <iostream>
using std::cout;

#include "DebugDelete.h"

int main()
{
    uniquePtr<int> p1(new int(1));
    // 移动构造函数检查
    uniquePtr<int> p2(std::move(p1));
    // 解引用检查
    cout << *p2 << '\n';
    // 有删除器的构造函数检查
    uniquePtr<char, DebugDelete> p3(new char('a'), DebugDelete());
    //reset()检查
    p3.reset();
    // 移动赋值运算符检查
    p1 = uniquePtr<int>(new int (2));
    // reset(q) 和 release()检查
    p2.reset(p1.release());
    cout << *p2 << '\n';
    return 0;
}