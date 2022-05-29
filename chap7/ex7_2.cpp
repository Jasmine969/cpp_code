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
    string& isbn() {return bookNo;}
    Sales_data combine(Sales_data&);
};

Sales_data Sales_data::combine(Sales_data& trans)
{
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    double price1 = 0;
    if (cin >> total.bookNo >> total.units_sold >> price1)
    {
        total.revenue = total.units_sold * price1;
        Sales_data trans;
        double price2 = 0;
        cout << "book No.\t\tUnits sold\tTotal price\t Avg price" << endl;
        while (cin >> trans.bookNo >> trans.units_sold >> price2)
        {
            trans.revenue = trans.units_sold * price2;
            if (total.bookNo == trans.bookNo)
            {
                total.combine(trans);
            }
            else
            {
                cout << total.isbn() << "\t" << total.units_sold << "\t\t\t" << total.revenue << "\t\t\t " << myRound(total.revenue / total.units_sold, 2) << "\n";
                total = trans;
            }
        }
        cout << total.isbn() << "\t" << total.units_sold << "\t\t\t" << total.revenue << "\t\t\t " << myRound(total.revenue / total.units_sold, 2) << "\n";
    }
    else
    {
        throw std::runtime_error("Empty data!?");
    }
    return 0;
}