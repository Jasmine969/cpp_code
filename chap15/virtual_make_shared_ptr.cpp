#include <memory>

class Base
{
public:
    virtual void fun() = 0;
    Base() = default;
protected:
    ~Base() = default;
};

class Derived : public Base
{
public:
    void fun() override {}
};

int main()
{
    std::shared_ptr<Base> p1; // 通过。_M_ptr创建空shared_ptr，并不创建Base对象
    // std::make_shared<Base>(); // 报错。make_shared<Base>在实现的时候要new Base，但Base是不能new的
    std::shared_ptr<Base> p2(new Derived); // 通过。Derived类可以new。
    // std::make_shared<Base>(Derived()); // 报错。make_shared<Base>在实现的时候要new Base，然后指向new的Derived对象。但Base是不能new的。
    // std::shared_ptr<Base> p3(new Base); // 报错。显式new Base，当然不允许。
    // Base* p4 = new Base; // 报错。显式new Base，当然不允许。
    return 0;
}