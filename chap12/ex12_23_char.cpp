#include <iostream>
#include <cstring>

using std::strlen;
using std::strcat;
using std::strcpy;
using std::cout;

char* concatChar(const char c1[], const char c2[])
{
    auto c = new char[strlen(c1) + strlen(c2)];
    strcpy(c, c1);
    strcat(c, c2);
    return c;
}

void fun()
{
    auto d = concatChar("I", "lOVE");
    // while (*d)
    // {
    //     cout << *d++ << ' ';
    // } // 不要这么做，因为会导致无法正常delete [] d
    cout << d << '\n';
    delete d;
}

int main()
{
    fun();
    return 0;
}