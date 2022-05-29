#include <iostream>
#include "../VisualStudio2012/1/Sales_item.h"

int main()
{
    Sales_item total, item;
    std::cout << "Enter book items:" << std::endl;
    if (std::cin >> total)
    {
        while (std::cin >> item)
            if (compareIsbn(total, item))
                total = total + item;
            else
            {
                std::cerr << "ISBN are not the same!" << std::endl;
                return -1;
            }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "Empty data!" << std::endl;
        return -1; 
    }
    return 0;
}