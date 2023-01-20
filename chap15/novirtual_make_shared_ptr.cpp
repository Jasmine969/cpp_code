#include <memory>

class Base
{
public:
    Base() = default;

protected:
    ~Base() = default;
};

class Derived : public Base
{
};

int main()
{
    std::shared_ptr<Base> p1; // 通过。_M_ptr创建空shared_ptr，并不创建Base对象
    // std::make_shared<Base>(); // 报错。有new Base操作，但Base的析构函数是protected的，不可访问。
    std::shared_ptr<Base> p2(new Derived); // 通过。Derived类可以new。
    // std::make_shared<Base>(Derived());     // 报错。有new Base操作，但Base的析构函数是protected的，不可访问。
    // std::shared_ptr<Base> p3(new Base); // 报错。有new Base操作，但Base的析构函数是protected的，不可访问。
    Base* p4 = new Base; // 通过。这里虽然显式new Base，但并没用shared_ptr管理。shared_ptr在引用计数为0的时候会自动调用其析构函数，但是普通指针并不会，除非delete p4，而delete p4时也会报同样的错误。
    return 0;
}