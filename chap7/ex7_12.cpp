#include "Sales_data_ex12.h"
#include <iostream>

using std::cout;

int main()
{
    Sales_data sale1;
    Sales_data sale2("123");
    Sales_data sale3("123", 4, 4.5);
    Sales_data sale4(cin);
    print(cout, sale1) << "\n";
    print(cout, sale2) << "\n";
    print(cout, sale3) << "\n";
    print(cout, sale4) << "\n";
    return 0;
}