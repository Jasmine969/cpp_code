#include <iostream>
#include <string>
#include <stdexcept>
#include "friend_class_window.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

int main()
{
    Window_mgr wm;
    wm.screens[0].display(cout);
    wm.clear(0);
    wm.screens[0].display(cout);
    return 0;
}