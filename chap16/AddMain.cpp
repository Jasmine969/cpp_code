#include <iostream>
template <typename T> T Add(T, T);
int main()
{
    std::cout << Add<int>(1, 2) << '\n';
    return 0;
}