#include <iostream>

using std::cout;

class Base
{
public:
    Base() = default;
    void pub_mem() {}
    int pub_me = 3;

protected:
    int prot_mem = 10;

private:
    char priv_mem = 5;
};

struct Pub_Derv : public Base
{
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base
{
    friend void foo();
    // void foo() { Base &br = *this; }
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

class Prv_Derv : private Base
{
public:
    using Base::Base;

private:
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : public Prv_Derv
{
    // void memfcn() { Base b; }
};

void memfcn(Base b) {}

int main()
{
    Pub_Derv d1;
    Prot_Derv d3;
    Prv_Derv d2;
    Base *p = &d1;
    // p = &d2;
    // p = &d3;
    Derived_from_Public dd1;
    Derived_from_Protected dd2;
    Derived_from_Private dd3;
    p = &dd1;
    // p = &dd2;
    // p = &dd3;
    return 0;
}