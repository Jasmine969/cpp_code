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

struct Sales_data
{
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0;
    const string& isbn() const {return bookNo;}
    Sales_data combine(Sales_data&);
};

Sales_data Sales_data::combine(Sales_data& trans)
{
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
}

Sales_data add(Sales_data& lhs, Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

ostream& print(ostream& os, const Sales_data& sale)
{
    os << sale.isbn() << "\t" << sale.units_sold << "\t\t\t" << sale.revenue << "\t\t\t " << myRound(sale.revenue / sale.units_sold, 2);
    return os;
}

istream& read(istream& is, Sales_data& sale)
{
    double price;
    is >> sale.bookNo >> sale.units_sold >> price;
    sale.revenue = sale.units_sold * price;
    return is;
}

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        cout << "book No.\t\tUnits sold\tTotal price\t Avg price" << endl;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        throw std::runtime_error("Empty data!?");
    }
    return 0;
}