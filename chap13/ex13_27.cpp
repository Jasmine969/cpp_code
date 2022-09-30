#include <iostream>
#include "HasPtr_ex27.h"
#include <string>

using std::cout;
using std::string;

int main()
{
    HasPtr hp("HELlo");
    HasPtr hp2;
    hp2 = hp;
    cout << hp.get_str() << '\t' << hp2.get_str() << '\n';
    hp.set_str("good");
    cout << hp.get_str() << '\t' << hp2.get_str() << '\n';
    hp2.set_str("GOOD");
    cout << hp.get_str() << '\t' << hp2.get_str() << '\n';
    return 0;
}