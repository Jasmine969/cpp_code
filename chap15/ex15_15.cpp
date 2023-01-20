#include "Bulk_quote.h"

int main()
{
    Bulk_quote bulk("abc-1", 12, 3, 0.3);
    print_total(cout, bulk, 10);
    return 0;
}