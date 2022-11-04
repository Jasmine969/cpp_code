#include "Sales_data_ex13.h"

int main()
{
    Sales_data sale1("A-1", 5, 1.2);
    Sales_data sale2("A-1",2, 1.5);
    cout << sale2 - sale1 << '\n';
    return 0;
}