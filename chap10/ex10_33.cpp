#include <iterator>
#include <fstream>
#include <iostream>

using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::ofstream;
using std::cout;

int main()
{
    ifstream inp("numbers.txt");
    ofstream f_odd("odd_num.txt"), f_even("even_num.txt");
    istream_iterator<int> in_iter(inp), eof;
    ostream_iterator<int> out_odd(f_odd, " "), out_even(f_even, "\n");
    while (in_iter != eof)
    {
        if (*in_iter & 1)
        {
            out_odd = *in_iter++;
        }
        else
        {
            out_even = *in_iter++;
        }
    }
    return 0;
}