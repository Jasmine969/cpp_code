#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Quote.h"

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &s, double p, size_t qty, double disc)
        : Quote(s, p), // 基类成员只能用基类的构造函数初始化
          min_qty(qty), discount(disc)
    {
    }
    double net_price(size_t n) const override;
    void fun() {}
    int g = 100;
private:
    size_t min_qty = 0;
    double discount = 1.0;
};

double Bulk_quote::net_price(size_t n) const
{
    if (n >= min_qty)
    {
        return n * (1 - discount) * price;
    }
    else
    {
        return n * price;
    }
}

#endif