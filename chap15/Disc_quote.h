#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &s, double price, size_t qty, double disc)
        : Quote(s, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;
    Disc_quote(const Disc_quote &);
    Disc_quote &operator=(const Disc_quote &);
    ~Disc_quote() {}

protected:
    size_t quantity = 0;
    double discount = 0.0;
};

Disc_quote::Disc_quote(const Disc_quote &d)
    : Quote(d), quantity(d.quantity), discount(d.discount) {}

Disc_quote &Disc_quote::operator=(const Disc_quote &rhs)
{
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

#endif