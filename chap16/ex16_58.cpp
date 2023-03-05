#include <iostream>
using std::cout;
#include "Vec.h"
#include <string>
using std::string;

int main()
{
    Vec<string> vs;
    vs.emplace_back(10, 'c');
    vs.emplace_back("hhh");
    vs.emplace_back(string("fe"));
    string ss("fwe");
    vs.emplace_back(ss);
    for (auto s : vs)
    {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}