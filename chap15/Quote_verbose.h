#ifndef QUOTE_VERBOSE_H
#define QUOTE_VERBOSE_H

#include <string>
#include <iostream>

using std::cout;
using std::ostream;
using std::string;

class Quote
{
    friend double print_total(ostream &, const Quote &, size_t);

public:
    Quote() = default;
    Quote(const string &s, double p) : bookNo(s), price(p) {}
    Quote(const Quote &);            // copy constructor
    Quote &operator=(const Quote &); // copy assigment operator
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() { cout << "Quote destructor\n"; };
    virtual void debug();

private:
    string bookNo;

protected:
    double price = 0.0;
};

Quote::Quote(const Quote &q)
    : bookNo(q.bookNo), price(q.price)
{
    cout << "Quote copy constructor\n";
}

Quote &Quote::operator=(const Quote &rhs)
{
    bookNo = rhs.bookNo;
    price = rhs.price;
    cout << "Quote copy assignment operator\n";
    return *this;
}

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