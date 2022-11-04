#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::allocator;
using std::string;

class Tracer
{
    private:
    string s;
public:
    Tracer(const string& ss): s(ss) {cout << "constructor\n";};
    Tracer(const Tracer &rhs): s(rhs.s) {cout << "copy constructor\n";} 
    ~Tracer() {cout << "destructor\n";};
};

int main()
{
    allocator<Tracer> alloc;
    Tracer tr("abc");
    auto p = alloc.allocate(10);
    alloc.construct(p++, "abc");
    alloc.destroy(--p);
    alloc.deallocate(p, 10);
    return 0;
}