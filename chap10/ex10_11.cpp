#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../myfunc.h"

using std::vector;
using std::string;
using std::stable_sort;
using std::sort;
using std::unique;
using std::cout;

inline bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

void elimDup(vector<string>& v)
{
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
    stable_sort(v.begin(), v.end(), isShorter);
}

int main()
{
    vector<string> vstr{"the", "red", "fox", "jumps", "over", "the", "red", "dog"};
    elimDup(vstr);
    printVec(vstr);
    return 0;
}