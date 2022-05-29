#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned int unints_sold = 0;
    double price = 0.0;
};

int main()
{
    Sales_data data1;
    if (std::cin >> data1.bookNo >> data1.unints_sold >> data1.price)
    {
        Sales_data data2;
        int count = 1;
        while (std::cin >> data2.bookNo >> data2.unints_sold >> data2.price)
            if (data1.bookNo == data2.bookNo)
            {
                double total_price = 0.0;
                total_price = data1.unints_sold * data1.price +
                              data2.unints_sold * data2.price;
                data1.unints_sold += data2.unints_sold;
                data1.price = total_price / data1.unints_sold;
                // std::cout << "-----" << std::endl;
            }
            else
            {
                std::cout << data1.bookNo << ' ' << data1.unints_sold << ' ' << data1.price << std::endl;
                data1 = data2;
                // std::cout << "======" << std::endl;
            }
        std::cout << data1.bookNo << ' ' << data1.unints_sold << ' ' << data1.price << std::endl;
    }
    else
        std::cout << "Empty data!" << std::endl;
    return 0;
}