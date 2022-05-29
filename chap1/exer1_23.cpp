#include <iostream>
#include "../VisualStudio2012/1/Sales_item.h"

int main()
{
    int num = 1;
    Sales_item item1, item2;
    if (std::cin >> item1)
    {
        while (std::cin >> item2)
            if (item1.isbn() == item2.isbn())
                ++num;
            else
            {
                std::cout << item1.isbn() << " has " << num << " records." << std::endl;
                num = 1;
                item1 = item2;
            }
        std::cout << item1.isbn() << " has " << num << " records." << std::endl;
    }
    else
    {
        std::cerr << "Empty data!" << std::endl;
        return -1; 
    }
    return 0;
}