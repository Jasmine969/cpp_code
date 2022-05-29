#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;    
};

int main()
{
    Sales_data item = {"978-0590353403", 25, 15.99};
    cout << item.bookNo << '\t' << item.units_sold << '\t' << item.revenue << endl;
    return 0;
}