#include "Screen_ex27.h"
#include <iostream>

using std::cout;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    return 0;
}
