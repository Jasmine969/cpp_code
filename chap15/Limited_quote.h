#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H

#include "Disc_quote.h"

class Limited_quote : public Disc_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const string &s, double p, size_t m, double disc)
        : Disc_quote(s, p, m, disc) {}
    double net_price(size_t n) const override;
};

double Limited_quote::net_price(size_t n) const
{
    if (n <= quantity)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return quantity * (1-discount) * price + (n - quantity) * price;
    }
}

#endif