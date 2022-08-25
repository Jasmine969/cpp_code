#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cout;

shared_ptr<int> factory(int i)
{
    return make_shared<int>(i);
}

shared_ptr<int> use_factory(int i)
{
    shared_ptr<int> p = factory(i);
    cout << "void use_factory: " << p.use_count() << '\n';
    return p;
}

int main()
{
    auto p1 = use_factory(2);
    cout << "int main: " << p1.use_count() << '\n';
    auto p2(p1);
    cout << "int main: " << p2.use_count() << '\n';
    return 0;
}