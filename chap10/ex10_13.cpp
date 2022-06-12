#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "../myfunc.h"

using std::partition;
using std::cout;
using std::string;
using std::vector;

inline bool five_more(const string& s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> vstr{"123", "123456", "12", "1234567", "123456", "12", "12345", "123"};
    auto five_end = partition(vstr.begin(), vstr.end(), five_more);
    for (auto iter = vstr.begin(); iter != five_end; ++iter)
    {
        cout << *iter << ' ';
    }
    cout << '\n';
    return 0;
}