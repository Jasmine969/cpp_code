#include <iostream>
#include <stdexcept>
#include "Sales_data_ex2.h"

using std::cin;
using std::cout;

int main()
{
    Sales_data total;
    if (cin >> total)
    {
        Sales_data trans;
        cout << "book No.\t\tUnits sold\tTotal price\t Avg price" << endl;
        while (cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                cout << total << "\n";
                total = trans;
            }
        }
        cout << total << "\n";
    }
    else
    {
        throw std::runtime_error("Empty data!?");
    }
    return 0;
}