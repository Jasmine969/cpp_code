#include "sharedPtr.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;

template <typename T, typename... Args>
sharedPtr<T> makeShared(Args&&... args)
{
    return sharedPtr<T>(new T (std::forward<Args>(args)...));
}

int main()
{
    auto p = makeShared<int>(1);
    cout << *p << ' ';
    auto p2 = makeShared<string>(10, 'c');
    cout << *p2 << ' ';
    auto p3 = makeShared<char>();
    cout << *p3 << ' ';
    char c = 'd', *pc = &c;
    int i = 1, *pi = &i;
    return 0;
}