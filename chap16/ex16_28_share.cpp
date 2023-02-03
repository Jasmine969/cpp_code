#include "sharedPtr.h"
#include <iostream>
using std::cout;

#include "DebugDelete.h"

int main()
{
    sharedPtr<int> p1(true);
    sharedPtr<int> p2(new int(2));
    cout << p2.use_count() << '\n';
    p1 = p2; // 拷贝赋值运算符检查
    cout << p1.use_count() << '\t' << p2.use_count() << '\n';
    p1 = sharedPtr<int>(); // 移动赋值运算符检查
    cout << "=======\n";
    // reset(q,d) 检查
    sharedPtr<int> p3(new int(4), DebugDelete(std::cout));
    p3.reset(new int(332), [](int *p)
             { delete p; });
    // 自赋值检查
    auto p4 = new int(100);
    sharedPtr<int> p5(p4);
    cout << p5.use_count() << '\n';
    p5.reset(p4);
    cout << p5.use_count() << '\n';
    // 解引用检查
    cout << *p5 << '\n';
    const sharedPtr<double> p6(new double (1.34));
    cout << *p6 << '\n';
    return 0;
}