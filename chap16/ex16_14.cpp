#include "Screen_chap16.h"
#include <iostream>

using std::cout;

int main()
{
    Screen<6,4> scr('f');
    scr.display(cout);
    cout << "\nend\n";
    scr.move(3,2).set('g');
    scr.display(cout);
    cout << "\nend\n";
    const Screen<5,3> blank;
    blank.display(cout);
    return 0;
}