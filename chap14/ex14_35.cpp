#include <iostream>
#include <string>
#include "ReadVec.h"

using std::cout;

int main()
{
    ReadString ps;
    auto s = ps();
    cout << s << '\n';
    return 0;
}