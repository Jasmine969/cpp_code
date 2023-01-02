#include <iostream>

using std::cout;

struct Base
{
    void f() { cout << "Base f\n"; }
    void f(char) { cout << "Base f char\n"; }
    void f(int) { cout << "Base f int\n"; }
    virtual void g(char) { cout << "Base g char\n"; }
    virtual void g(int) { cout << "Base g int\n"; }
    virtual void h() { cout << "Base h\n"; }
};

struct Derived : public Base
{
    void f() { cout << "Derived f\n"; }
    void f(char) { cout << "Derived f char\n"; }
    void f(double) { cout << "Derived f double\n"; }
    virtual void g() { cout << "Derived g\n"; }
    virtual void g(char) { cout << "Derived g char\n"; }
    virtual void g(double) { cout << "Derived g double\n"; }
    // virtual int h() { return 1; } // error: conflicting return type specified for 'virtual int Derived::h()'
    using Base::f;
};

int main()
{
    Derived d;
    Base *bp = &d;
    d.f();
    d.f(1);
    cout << "====\n";
    bp->f();
    bp->f(1);
    cout << "====\n";
    d.g(1.1);
    d.g('a');
    // d.g(1); 
    // virtual void Derived::g(char) or virtual void Derived::g(double)
    cout << "====\n";
    // bp->g(); // candidate expects 1 argument, 0 provided
    bp->g('a'); 
    bp->g(1);
    // bp->g(1.1); // virtual void Base::g(char) or virtual void Base::g(int)
    cout << "====通过作用域运算符调用另一函数\n";
    d.Base::f();
    bp->Base::g('a');
    return 0;
}