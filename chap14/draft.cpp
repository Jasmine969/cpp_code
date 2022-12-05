#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <vector>
#include "StrBlobPtr_chap14.h"
#include <functional>
#include <map>
#include <cstring>

using std::bitset;
using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::vector;
using namespace std::placeholders;
using std::modulus;
using std::function;
using std::strcmp;

int main()
{
    const char* cp = "h2o";
    cout << (0 == strcmp(cp, "h2o")) << ' ' << (0 == strcmp(cp, "H2O")) << '\n';
    if (cp=="h2o" || cp=="H2O")
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}
