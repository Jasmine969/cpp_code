#include <iostream>

using std::cout;
using std::endl;

void f(){cout << "f1 called" << endl;}
void f(int){cout << "f2 called" << endl;}
void f(int, int){cout << "f3 called" << endl;}
void f(double, double = 3.14){cout << "f4 called" << endl;}
int main()
{
    // f(2.56, 42); // ambiguous call
    f(42);
    f(42,0);
    f(2.56, 3.14);
    return 0;
}