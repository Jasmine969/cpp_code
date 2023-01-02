#include "Bulk_quote_verbose.h"

int main()
{
    Bulk_quote bulk1;
    Bulk_quote bulk2(bulk2);
    cout << "=====\n";
    bulk1 = bulk2;
    return 0;
}