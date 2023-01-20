#include <iostream>
#include <string>
#include <algorithm>
#include "Blob.h"
#include <functional>
#include <vector>
#include <iterator>

using std::cout;
using std::string;
using namespace std::placeholders;
using std::vector;
using std::back_inserter;

bool isShorter(const string &s, size_t sz=4)
{
    return s.size() < sz;
}

int main()
{
    cout << '\n';
    return 0;
}