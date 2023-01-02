#include "Basket.h"

int main()
{
    Basket basket;
    basket.add_item(Quote("123-2", 10));
    basket.add_item(Bulk_quote("123-3", 10, 3, 0.3));
    basket.add_item(Bulk_quote("123-3", 10, 3, 0.3));
    basket.add_item(Quote("123-2", 10));
    basket.add_item(Bulk_quote("123-3", 10, 3, 0.3));
    basket.add_item(Quote("123-2", 10));
    basket.add_item(Quote("123-2", 10));
    basket.add_item(Bulk_quote("123-3", 10, 3, 0.3));
    basket.add_item(Bulk_quote("123-3", 10, 3, 0.3));
    basket.add_item(Quote("1",20));
    basket.total_receipt(cout);
    return 0;
}