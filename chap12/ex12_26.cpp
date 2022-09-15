#include <memory>
#include <iostream>
#include <string>

using std::allocator;
using std::cin;
using std::cout;
using std::string;

int main()
{
    allocator<string> alloc;
    unsigned n = 6;
    // 分配内存
    auto const p = alloc.allocate(n); // p始终指向首元素
    auto q = p;                       // q用来移动
    string s;
    // 构造对象
    while (cin >> s && q != p + n)
    {
        alloc.construct(q++, s);
    }
    auto size = q - p;
    for (unsigned i = 0; i != size; ++i)
    {
        cout << p[i] << ' ';
    }

    cout << "\n" << size << " words has been read!\n";
    // 析构对象
    while (q != p)
    {
        alloc.destroy(--q);
    }
    // 释放内存
    alloc.deallocate(p, n);
    return 0;
}