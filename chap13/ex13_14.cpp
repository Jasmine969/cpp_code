#include "numberd_ex16_copy.h"

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}