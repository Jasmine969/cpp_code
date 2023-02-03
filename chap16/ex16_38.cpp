#include <memory>
using std::make_shared;

#include <iostream>
using std::cout;

int main()
{
    auto p = make_shared<int>(4.9);
    cout << *p << '\n';
    return 0;
}