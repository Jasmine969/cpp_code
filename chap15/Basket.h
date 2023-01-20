#ifndef BASKET_H
#define BASKET_H

#include <memory>
#include "Bulk_quote.h"
#include <set>
#include <iostream>

using std::multiset;
using std::ostream;
using std::shared_ptr;

class Basket
{
private:
    static bool compare(
        const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};

public:
    void add_item(const shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    void add_item(const Quote &sale)
    {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale)
    {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(ostream &) const;
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0;
    for (auto iter = items.cbegin();
         iter != items.cend();
         iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total sale: " << sum << '\n';
    return sum;
}

#endif