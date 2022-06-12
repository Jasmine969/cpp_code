#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../myfunc.h"
#include "../chap7/Sales_data_ex21.h"

using std::cout;
using std::stable_sort;
using std::string;
using std::vector;

inline bool compareIsbn(const Sales_data &sale1, const Sales_data &sale2)
{
    return sale1.isbn() < sale2.isbn();
}

int main()
{
    auto sale1 = Sales_data("123-a");
    auto sale2 = Sales_data("12-a");
    auto sale3 = Sales_data("123-b");
    auto sale4 = Sales_data("00000000");
    vector<Sales_data> vsale{sale1, sale2, sale3, sale4};
    stable_sort(vsale.begin(), vsale.end(), compareIsbn);
    for (auto sale : vsale)
    {
        cout << sale.isbn() << "\n";
    }
    return 0;
}