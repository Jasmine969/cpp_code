#include <iostream>
#include "../VisualStudio2012/1/Sales_item.h"
#include <fstream>
#include <iterator>

using std::cerr;
using std::cout;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
    ifstream in("book_records.txt");
    istream_iterator<Sales_item> in_iter(in), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    if (in_iter != eof)
    {
        Sales_item total = *in_iter++;
        while (in_iter != eof)
        {
            if (total.isbn() == in_iter->isbn())
                total += *in_iter++;
            else
            {
                out_iter = total;
                total = *in_iter++;
            }
        }
        out_iter = total;
    }
    else
    {
        cerr << "Empty data!" << '\n';
        return -1;
    }
    return 0;
}