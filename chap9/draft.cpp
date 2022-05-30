#include <string>
#include <iostream>

using std::string;
using std::cout;

int main()
{
    string s("a");
    cout << s.find("l", 1) << '\n';
    cout << s.find("ll") << '\n';
    cout << s.find("lll") << '\n';
    cout << string::npos << '\n';
    return 0;
}