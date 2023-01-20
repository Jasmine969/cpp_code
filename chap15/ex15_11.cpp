#include "Bulk_quote_ex11.h"

int main()
{
    Bulk_quote bulk("abc-1", 12, 3, 0.3);
    Quote quote(bulk);
    quote.debug();
    cout << "\n";
    bulk.debug();
    return 0;
}