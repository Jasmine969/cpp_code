#ifndef SALES_DATA_EX41_H
#define SALES_DATA_EX41_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data;
istream &read(istream &is, Sales_data &sale);
ostream &print(ostream &os, const Sales_data &sale);
Sales_data add(Sales_data &lhs, Sales_data &rhs);

class Sales_data
{
    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);
public:
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;

public:
    const string &isbn() const { return bookNo; }
    Sales_data &combine(Sales_data &);
    double avg_price() const;

    Sales_data(const string &s, unsigned n, double p) : bookNo{s}, units_sold(n), revenue(p * n) { cout << "1 finished" << '\n'; };
    Sales_data() : Sales_data("", 0, 0) { cout << "2 finished" << '\n'; }
    Sales_data(const string &s) : Sales_data(s, 0, 0) { cout << "3 finished" << '\n'; };
    Sales_data(istream &is) : Sales_data("1234")
    {
        read(is, *this);
        cout << "4 finished"
             << "\n";
    }
};



ostream &print(ostream &os, const Sales_data &sale)
{
    os << sale.isbn() << "\t" << sale.units_sold << "\t\t\t" << sale.revenue;
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