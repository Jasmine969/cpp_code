#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned int unints_sold = 0;
    // double revenue = 0.0;
};

int main()
{
    Sales_data data1;
    double price1 = 0.0;
    if (std::cin >> data1.bookNo >> data1.unints_sold >> price1)
    {
        Sales_data data2;
        int count = 1;
        double price2 = 0.0;
        while (std::cin >> data2.bookNo >> data2.unints_sold >> price2)
            if (data1.bookNo == data2.bookNo)
            {
                ++count;
                // std::cout << "-----" << std::endl;
            }    
            else
            {
                std::cout << data1.bookNo << " has " << count << " record(s)." << std::endl;
                data1 = data2;
                price1 = price2;
                count = 1;
                // std::cout << "======" << std::endl;
            }
        std::cout << data1.bookNo << " has " << count << " record(s)." << std::endl;
    }
    else
        std::cout << "Empty data!" << std::endl;
    return 0;
}