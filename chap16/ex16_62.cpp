#include "Sales_data_chap16.h"
#include <iostream>
using std::cout;
#include <unordered_set>

int main()
{
    std::unordered_multiset<Sales_data> sales;
    sales.emplace("123-1", 4, 12.5);
    sales.emplace("234", 3, 1.2);
    sales.emplace("0001", 100, 54);
    for (auto it = sales.begin(); it != sales.end(); ++it)
    {
        cout << *it << '\n';
    }
    return 0;
}