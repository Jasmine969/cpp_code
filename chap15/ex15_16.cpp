#include "Limited_quote.h"

int main()
{
    Limited_quote limit("abc-1", 12, 4, 0.3);
    print_total(cout, limit, 10);
    print_total(cout, limit, 3);
    return 0;
}