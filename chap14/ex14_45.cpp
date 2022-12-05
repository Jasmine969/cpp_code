#include "Sales_data_chap14.h"

int main()
{
    Sales_data sale1{"101-1",10, 5.1};
    cout << static_cast<double>(sale1) + 1 << '\n';
    cout << static_cast<string>(sale1) + " hhh" << '\n';
    return 0;
}