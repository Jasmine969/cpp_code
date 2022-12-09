#include <iostream>

using std::cout;

struct Base
{
    int i = 10;
};

struct Derived : public Base
{
    char c = 'a';
};

int main()
{
    Derived d;
    Base* pb = &d;
    (*pb).i;
    return 0;
}