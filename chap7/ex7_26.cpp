#include <iostream>
#include <stdexcept>
#include "..\myfunc.h"
#include "Sales_data_ex26.h"

using std::cin;
using std::cout;
using std::endl;

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