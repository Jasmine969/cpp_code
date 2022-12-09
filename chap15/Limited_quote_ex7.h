#ifndef LIMITED_QUOTE_EX7_H
#define LIMITED_QUOTE_EX7_H

#include "Quote.h"

class Limited_quote : public Quote
{
private:
    size_t max_qty = 10;
    double discount = 0.0;

public:
    Limited_quote() = default;
    Limited_quote(const string &s, double p, size_t m, double disc)
        : Quote(s, p), max_qty(m), discount(disc) {}
    double net_price(size_t n) const override;
};

double Limited_quote::net_price(size_t n) const
{
    if (n <= max_qty)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return max_qty * (1-discount) * price + (n - max_qty) * price;
    }
}
#endif