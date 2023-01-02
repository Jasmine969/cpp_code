#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    // Bulk_quote(const string &s, double p, size_t qty, double disc)
    //     : Disc_quote(s, p, qty, disc)
    // {
    // }
    using Disc_quote::Disc_quote;
    Bulk_quote(const Bulk_quote &);
    Bulk_quote &operator=(const Bulk_quote &);
    double net_price(size_t n) const override;
    void debug() override;
    ~Bulk_quote() {}
    virtual Bulk_quote *clone() const &
    {
        return new Bulk_quote(*this);
    }
    virtual Bulk_quote *clone() &&
    {
        return new Bulk_quote(std::move(*this));
    }
};

Bulk_quote::Bulk_quote(const Bulk_quote &b)
    : Disc_quote(b) {}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    Disc_quote::operator=(rhs);
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