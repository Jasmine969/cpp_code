#include "..\chap2\Sales_data.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "..\myfunc.h"

using std::cerr;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::string;

// 要打印的：bookNo 册数 总销售额 平均售价 不要打印：单价
void add(Sales_data &sale1, Sales_data &sale2)
{
    if (sale1.bookNo == sale2.bookNo)
    {
        sale1.price = (sale1.price * sale1.units_sold + sale2.price * sale2.units_sold) / (sale1.units_sold + sale2.units_sold);
        sale1.units_sold += sale2.units_sold;
    }
    else
    {
        throw std::runtime_error("The book No. are not the same!");
    }
}
// istream 和 ostream 必须定义成引用类型才能进行后续操作
istream &read(istream &stream_fun, Sales_data &sale)
{
    return stream_fun >> sale.bookNo >>
           sale.units_sold >> sale.price;
}

ostream &print(ostream &cfun, Sales_data sale)
{
    return cfun << sale.bookNo << "\t" << sale.units_sold << "\t\t\t" << sale.units_sold * sale.price << "\t\t\t " << myRound(sale.price, 2);
}

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        output << "book No.\t\tUnits sold\tTotal price\t Avg price" << endl;
        while (read(input, trans))
        {
            if (total.bookNo == trans.bookNo)
            {
                add(total, trans);
            }
            else
            {
                print(output, total) << '\n';
                total = trans;
            }
        }
        print(output, total) << '\n';
    }
    else
    {
        throw std::runtime_error("Empty data!?");
    }
    return 0;
}