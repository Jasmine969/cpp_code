#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

using std::ostream;
using std::string;
using std::cout;

class Quote
{
    friend double print_total(ostream &, const Quote &, size_t);

public:
    Quote() = default;
    Quote(const string &s, double p) : bookNo(s), price(p) {}
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;
    virtual void debug();

private:
    string bookNo;

protected:
    double price = 0.0;
};

void Quote::debug()
{
    cout << "bookNo:\t" << isbn() << "\tprice:\t" << price << "\n";
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN " << item.isbn() << " # sold: "
       << n << " total due: " << ret << '\n';
    return ret;
}

#endif