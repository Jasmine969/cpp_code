#include <iostream>
#include "E:\cpp_code\VisualStudio2012\1\Sales_item.h"

int main()
{
    Sales_item item_total, item1;
    std::cin >> item_total;
    while (std::cin >> item1)
        item_total = item_total + item1;
    std::cout << item_total << std::endl;
    return 0;
}