#include <iostream>
#include <string>
#include <vector>
#include "ReadVec.h"
#include <iterator>
#include <algorithm>

using std::cout;
using std::vector;
using std::ostream_iterator;
using std::copy;

int main()
{
    ReadString ps;
    vector<string> svec;
    string line;
    do
    {
        line = ps();
        svec.push_back(line);
    }
    while (!line.empty());
    ostream_iterator<string> oit(cout, " ");
    copy(svec.begin(), svec.end(), oit);
    return 0;
}