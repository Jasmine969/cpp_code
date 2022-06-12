#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../myfunc.h"

using std::vector;
using std::string;
using std::sort;
using std::unique;
using std::cout;

void elimDup(vector<string>& v)
{
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}

int main()
{
    vector<string> vstr{"the", "red", "fox", "jumps", "over", "the", "red", "dog"};
    elimDup(vstr);
    printVec(vstr);
    return 0;
}