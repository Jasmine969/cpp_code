#include <iostream>
#include <string>
#include <set>
#include <map>
#include <memory>
#include <algorithm>
#include <iterator>
#include "../myfunc.h"
#include <numeric>
// #include "Query_chap15.h"

using std::cout;
using std::map;
using std::multimap;
using std::multiset;
using std::set;
using std::string;

class Base
{
public:
    int i;

protected:
    int j;

private:
    int k;
};

class Derived : protected Base
{
};

bool compare(const string &lhs, const string &rhs)
{
    return lhs < rhs;
}

int main()
{
    vector<int> file(10);
    set<unsigned> all_lines;
    for (unsigned i = 1; i != file.size(); ++i)
    {
        all_lines.insert(i);
    }
    
    return 0;
}