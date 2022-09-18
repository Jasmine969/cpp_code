#include <iostream>
#include <memory>
#include <list>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::list;

struct X
{
    X() { cout << "X()" << endl; }                  // default constructor
    X(const X &) { cout << "X(const X&)" << endl; } // copy constructor
    X &operator=(const X &)                         // copy assignment operator
    {
        cout << "X& operator=(const X&)" << endl;
        return *this;
    }
    ~X() { cout << "~X" << endl; } // destructor
};

void fun_nonref(X) {}
void fun_ref(X &) {}

int main()
{
    X x;
    cout << "====fun_nonref" << '\n';
    fun_nonref(x);
    cout << "====fun_ref" << '\n';
    fun_ref(x);
    cout << "====new without x, value initialization" << '\n';
    auto p1= new X();
    cout << "====new without x, default initialization" << '\n';
    auto p2 = new X;
    cout << "====new with x" << '\n';
    auto p3 = new X(x);
    cout << "====shared_ptr without x, value initialization" << '\n';
    shared_ptr<X> p4 = make_shared<X>();
    cout << "====shared_ptr without x, default initialization" << '\n';
    shared_ptr<X> p5(new X);
    cout << "====shared_ptr with x" << '\n';
    shared_ptr<X> p6 = make_shared<X>(x);
    cout << "====create a list\n";
    list<X> lx;
    cout << "====push_back x\n"; // 拷贝初始化
    lx.push_back(x);
    cout << "====emplace_back\n"; // 直接初始化
    lx.emplace_back();
    cout << "====copy assignment operator\n";
    *lx.begin() = x;
    cout << "====end" << '\n';
    return 0;
}