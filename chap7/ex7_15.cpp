#include <iostream>
#include "Person_ex15.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Person p1;
    Person p2("Jasmine");
    Person p3("Jasmine", "Nanjing");
    Person p4(cin);
    print(cout, p1) << endl;
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    print(cout, p4) << endl;
}