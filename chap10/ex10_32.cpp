#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../VisualStudio2012/1/Sales_item.h"
#include <iterator>
#include <numeric>

using std::cout;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::string;
using std::vector;
using std::find_if;
using std::accumulate;

inline bool myCompareIsbn(const Sales_item &sale1, const Sales_item &sale2)
{
    return sale1.isbn() < sale2.isbn();
}

int main()
{
    ifstream inp("book_records.txt");
    istream_iterator<Sales_item> in_iter(inp), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    vector<Sales_item> vsale(in_iter, eof);
    sort(vsale.begin(), vsale.end(), myCompareIsbn);
    auto vs_iter = vsale.begin();
    while (vs_iter != vsale.end())
    {
        auto vs_next = find_if(vs_iter + 1, vsale.end(),
        [vs_iter] (Sales_item sale) {return !compareIsbn(sale, *vs_iter);});
        out_iter = accumulate(vs_iter + 1, vs_next, *vs_iter);
        vs_iter = vs_next;
    }
    return 0;
}