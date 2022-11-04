#include <iostream>
#include <string>
#include <iomanip>
#include <bitset>
#include "HasPtr_ex30test.h"
#include <vector>

using std::bitset;
using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::vector;

int main()
{
    const vector<int> v{1,2};
    auto it = v.begin();
    const HasPtr hp(0, "hello");
    cout << hp.get_str() << '\n';
    hp.get_str() = "jesus";
    cout << hp.get_str() << '\n';
    return 0;
}
