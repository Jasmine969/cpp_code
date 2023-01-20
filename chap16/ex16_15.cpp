#include "Screen_chap16.h"

using std::cout;

int main()
{
    Screen<5,3> scr('h');
    cout << scr << '\n';
    std::cin >> scr;
    cout << scr << '\n';
    return 0;
}