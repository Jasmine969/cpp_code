#include <iostream>
using std::cout;

template <typename T>
void f(T) { cout << "f(T)\n"; }
template <typename T>
void f(const T *) { cout << "f(const T *)\n"; }
template <typename T>
void g(T) { cout << "g(T)\n"; }
template <typename T>
void g(T *) { cout << "g(T *)\n"; }

int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);
    f(ci);
    f(p2);
    return 0;
}