#include "Bulk_quote.h"
#include <iostream>

using std::cout;

int main()
{
    Bulk_quote bulk("1-23", 12, 3, 0.3);
    print_total(cout, bulk, 10);
    return 0;
}