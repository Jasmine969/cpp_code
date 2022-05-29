#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    const char ca[] = "hello";
    const char cb[] = "thx";
    cout << strcmp(ca, cb) << endl;
    return 0;
}