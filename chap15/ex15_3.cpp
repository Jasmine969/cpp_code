#include <iostream>
#include "Quote.h"

using std::cout;

int main()
{
    Quote item("1-23", 23);
    print_total(cout, item, 2);
    return 0;
}