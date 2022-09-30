#include "Employee_ex18.h"
#include <iostream>

using std::cout;

int main()
{
    Employee p1("zhu hong");
    Employee p2;
    cout << p1.getName() << '\t' << p1.getId() << '\n';
    cout << p2.getName() << "\t\t" << p2.getId() << '\n';
    return 0;
}