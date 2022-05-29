#ifndef SALES_DATA_EX14_H
#define SALES_DATA_EX14_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "..\myfunc.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

struct Sales_data;
istream &read(istream &is, Sales_data &sale);

struct Sales_data
{
    string bookNo;
    unsigned int units_sold;
    double revenue;
    const string &isbn() const { return bookNo; }
    Sales_data combine(Sales_data &);

    // Sales_data() = default; // default constructor
    Sales_data() : bookNo(10,'a'), units_sold(0), revenue(0.0) {};
};

Sales_data Sales_data::combine(Sales_data &trans)
{
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

ostream &print(ostream &os, const Sales_data &sale)
{
    os << sale.isbn() << "\t" << sale.units_sold << "\t\t\t" << sale.revenue << "\t\t\t " << myRound(sale.revenue / sale.units_sold, 2);
    return os;
}

istream &read(istream &is, Sales_data &sale)
{
    double price;
    is >> sale.bookNo >> sale.units_sold >> price;
    sale.revenue = sale.units_sold * price;
    return is;
}

#endif