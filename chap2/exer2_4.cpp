#include <iostream>

int main()
{
    int i = -10, i2 = 42;
    std::cout << i << std::endl;          // -10
    std::cout << 2 * i + i2 << std::endl; // 22
    std::cout << 5 * i + i2 << std::endl; // -8
    return 0;
}