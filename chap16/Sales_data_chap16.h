#ifndef SALES_DATA_CHAP16_H
#define SALES_DATA_CHAP16_H

#include <iostream>
#include <string>
#include "..\myfunc.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

// class Sales_data;
// template <typename T> class std::hash;
// template <>
// std::hash<Sales_data>;
class Sales_data
{
    friend istream &operator>>(istream &, Sales_data &);
    friend ostream &operator<<(ostream &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend Sales_data operator-(const Sales_data &, const Sales_data &);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend class std::hash<Sales_data>;

private:
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;

public:
    const string &isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    Sales_data(const string &s, unsigned n, double p)
        : bookNo{s}, units_sold(n), revenue(p * n){};
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(const string &s) : Sales_data(s, 0, 0) {}
    Sales_data(istream &is)
    {
        cin >> *this;
    }
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator-=(const Sales_data &);
    Sales_data &operator=(const string &);
    explicit operator string() const;
    explicit operator double() const;
};

inline double Sales_data::avg_price() const
{
    return units_sold ? myRound(revenue / units_sold, 2) : 0;
}

Sales_data &Sales_data::combine(const Sales_data &trans)
{
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
}

istream &operator>>(istream &is, Sales_data &sale)
{
    double price;
    is >> sale.bookNo >> sale.units_sold >> price;
    sale.revenue = sale.units_sold * price;
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &sale)
{
    os << sale.isbn() << "\t" << sale.units_sold << "\t\t\t"
       << sale.revenue << "\t\t\t" << sale.avg_price();
    return os;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    this->combine(rhs);
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data new_sale(lhs);
    new_sale += rhs;
    return new_sale;
}

Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
    if (units_sold < rhs.units_sold || revenue < rhs.revenue)
    {
        std::cerr << "Invalid units_sold or revenue!\n";
    }
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sub(lhs);
    sub -= rhs;
    return sub;
}

Sales_data &Sales_data::operator=(const string &s)
{
    bookNo = s;
    return *this;
}

Sales_data::operator string() const
{
    return bookNo;
}

Sales_data::operator double() const
{
    return revenue;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.bookNo == rhs.bookNo &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

namespace std
{
    template <>
    struct hash<Sales_data>
    {
        typedef Sales_data argument_type;
        typedef size_t result_type;
        result_type operator()(const Sales_data &sale) const;
    };
    hash<Sales_data>::result_type
    hash<Sales_data>::operator()(const Sales_data &sale) const
    {
        cout << "call hash of " << sale.bookNo << '\n';
        return hash<string>()(sale.bookNo) ^
               hash<unsigned>()(sale.units_sold) ^
               hash<double>()(sale.revenue);
    }
}
#endif