#include "myFind.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>

using std::cout;
using std::vector;
using std::list;
using std::string;

int main()
{
    vector<int> vint{5,1,7,43};
    auto vret = myFind(vint.begin(), vint.end(), 7);
    cout << vret - vint.begin() << '\n';
    list<string> lstr{"I", "love", "you"};
    auto sret = myFind(lstr.begin(), lstr.end(), "jfieo");
    if (sret != lstr.end())
        cout << *sret;
    else
        cout << "no matched results of sret\n";
    return 0;
}