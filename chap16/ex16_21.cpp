#include "DebugDelete.h"

int main()
{
    auto p1 = new int(10);
    auto p2 = new char('p');
    DebugDelete d;
    d(p1);
    DebugDelete(std::cout)(p2);
    return 0;
}