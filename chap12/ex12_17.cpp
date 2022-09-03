#include <memory>

typedef std::unique_ptr<int> IntP;

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int (2048);
    // IntP p0(ix);
    IntP p1(pi);
    // IntP p2(pi2);
    // IntP p5(p2.get());
    return 0;
}