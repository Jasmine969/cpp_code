#include <iostream>
#include "Sales_data_ex12.h"

using std::cin;
using std::cout;

int main()
{
    Sales_data total(cin);
    if (cin)
    {
        cout << "book No.\t\tUnits sold\tTotal price\t Avg price" << endl;
        Sales_data trans;
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