#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include <vector>
#include "StrVec_chap14.h"
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
using std::function;
using std::modulus;
using std::strcmp;

int main()
{
    StrVec sv{"i", "LOVE", "YOU"};
    StrVec *psv = new StrVec(sv);
    cout << string(10, '-') << '\n';
    *psv = sv;
    cout << string(10, '-') << '\n';
    *psv = StrVec(sv);
    cout << string(10, '-') << '\n';
    delete psv;
    return 0;
}
