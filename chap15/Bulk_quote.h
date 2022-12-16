#ifndef BULK_QUOTE_EX11_H
#define BULK_QUOTE_EX11_H

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &s, double p, size_t qty, double disc)
        : Disc_quote(s, p, qty, disc)
    {
    }
    double net_price(size_t n) const override;
    void debug() override;
};

void Bulk_quote::debug()
{
    Quote::debug();
    cout << "min_qty:\t" << quantity << "\tdiscount:\t" << discount << "\n";
}

double Bulk_quote::net_price(size_t n) const
{
    if (n >= quantity)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return n * price;
    }
}

#endif