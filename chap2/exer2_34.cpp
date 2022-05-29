#include <iostream>

int main()
{
    int i = 0, &r= i;
    auto a = r;
    const int ci = 10, &cr = ci;
    auto b =ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    a = 42;
    b = 42;
    c = 42;
    // d = i + 1;
    // e = 42;
    // g = 42;
    std::cout << a << ' ' << b << ' ' << c << std::endl;
    auto *p = &ci;
    auto p1 = &ci;
    std::cout << p << ' ' << p1 << ' ' << *p << ' ' << *p1 << std::endl;
    
    return 0;
}
