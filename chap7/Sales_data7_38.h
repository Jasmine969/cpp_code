#ifndef SALES_DATA7_38_H
#define SALES_DATA7_38_H

#include <iostream>
#include <string>

using std::cin;
using std::istream;
using std::string;

struct Sales_data
{
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
    Sales_data(istream &is = cin)
    {
        is >> bookNo >> units_sold >> revenue;
    }
    // Sales_data(const string& s = ""): bookNo(s) {} // ex7_39
};

#endif