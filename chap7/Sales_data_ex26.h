#ifndef SALES_DATA_EX26_H
#define SALES_DATA_EX26_H

#include <iostream>
#include <string>
#include "..\myfunc.h"

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::string;

class Sales_data;
// 在友元声明前声明三个非成员函数
istream &read(istream &is, Sales_data &sale);
ostream &print(ostream &os, const Sales_data &sale);
Sales_data add(Sales_data &lhs, Sales_data &rhs);

class Sales_data
{
    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data&);
    friend Sales_data add(Sales_data &lhs, Sales_data &rhs);
private:
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;

public:
    const string &isbn() const { return bookNo; }
    Sales_data& combine(Sales_data &);
    double avg_price() const;

    Sales_data() = default; // default constructor
    Sales_data(const string &s) : bookNo(s){};
    Sales_data(const string &s, unsigned n, double p) : bookNo{s}, units_sold(n), revenue(p * n){};
    Sales_data(istream &is)
    {
        read(is, *this);
    }
};

Sales_data& Sales_data::combine(Sales_data &trans)
{
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
}

inline double Sales_data::avg_price() const
{
    return units_sold ? myRound(revenue / units_sold, 2) : 0;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

ostream &print(ostream &os, const Sales_data &sale)
{
    os << sale.isbn() << "\t" << sale.units_sold << "\t\t\t" << sale.revenue << "\t\t\t " << sale.avg_price();
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