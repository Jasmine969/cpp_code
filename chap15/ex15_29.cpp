#include <iostream>
#include "Bulk_quote.h"
#include <vector>
#include <memory>

using std::cout;
using std::vector;
using std::shared_ptr;
using std::make_shared;

int main()
{
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("123-2",10));
    basket.push_back(make_shared<Bulk_quote>("123-3", 10, 3, 0.3));
    cout << basket[0]->net_price(5) + basket[1]->net_price(5) << '\n';
    return 0;
}