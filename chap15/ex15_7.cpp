#include "Limited_quote_ex7.h"
#include <iostream>

using std::cout;

int main()
{
    Limited_quote max("1-23", 12, 3, 0.3);
    print_total(cout, max, 10);
    return 0;
}