#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "hello";
    string s2 = "thx";
    if (s1 > s2)
        cout << "s1 large" << endl;
    else if (s1 < s2)
        cout << "s2 large" << endl;
    else
        cout << "equal" << endl;
    return 0;
}