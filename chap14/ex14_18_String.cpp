#include "String_chap14.h"
#include <iostream>

using std::cout;

int main()
{
    String s1("isotherm");
    String s2("gosh");
    String s3("isotherm");
    String s4("isothermal");
    cout << std::boolalpha << (s1 < s2) << '\t' << (s1 < s3)
         << '\t' << (s1 < s4) << '\n';
    return 0;
}