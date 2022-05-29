#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    char ca[] = "hello ";
    char cb[] = "world";
    char cc[100] = {};
    strcpy(cc, ca);
    strcat(cc, cb);
    cout << cc << endl;
    return 0;
}