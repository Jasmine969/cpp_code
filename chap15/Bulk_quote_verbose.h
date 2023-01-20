#ifndef BULK_QUOTE_VERBOSE_H
#define BULK_QUOTE_VERBOSE_H

#include "Disc_quote_verbose.h"

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &s, double p, size_t qty, double disc)
        : Disc_quote(s, p, qty, disc) {}
    Bulk_quote(const Bulk_quote &);
    Bulk_quote &operator=(const Bulk_quote &);
    double net_price(size_t n) const override;
    void debug() override;
    ~Bulk_quote() { cout << "Bulk_quote destructor\n"; }
};

Bulk_quote::Bulk_quote(const Bulk_quote &b)
    : Disc_quote(b)
{
    cout << "Bulk_quote copy constructor\n";
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    Disc_quote::operator=(rhs);
    cout << "Bulk_quote copy assignment operator\n";
    return *this;
}

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