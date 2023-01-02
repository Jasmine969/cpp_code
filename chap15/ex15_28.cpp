#include <iostream>
#include "Bulk_quote.h"
#include <vector>

using std::cout;
using std::vector;

int main()
{
    vector<Quote> basket;
    basket.emplace_back("123-2", 10);
    basket.push_back(Bulk_quote("123-3", 10, 3, 0.3));
    cout << basket[0].net_price(5) + basket[1].net_price(5) << '\n';
    return 0;
}