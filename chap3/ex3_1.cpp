#include <iostream>
using std::cin;
using std::endl;
using std::cout;

struct Sales_data
{
    std::string bookNo;
    unsigned int unints_sold = 0;
    double price = 0.0;
};

int main()
{
    Sales_data data1;
    if (cin >> data1.bookNo >> data1.unints_sold >> data1.price)
    {
        Sales_data data2;
        int count = 1;
        while (cin >> data2.bookNo >> data2.unints_sold >> data2.price)
            if (data1.bookNo == data2.bookNo)
            {
                double total_price = 0.0;
                total_price = data1.unints_sold * data1.price +
                              data2.unints_sold * data2.price;
                data1.unints_sold += data2.unints_sold;
                data1.price = total_price / data1.unints_sold;
            }
            else
            {
                cout << data1.bookNo << ' ' << data1.unints_sold << ' ' << data1.price << endl;
                data1 = data2;
            }
        cout << data1.bookNo << ' ' << data1.unints_sold << ' ' << data1.price << endl;
    }
    else
        cout << "Empty data!" << endl;
    return 0;
}