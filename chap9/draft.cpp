#include <string>
#include <iostream>

using std::string;
using std::cout;

int main()
{
    string s = "some string", s2 = "some other string";
    s.insert(s.begin() + 2, s2.begin(), s2.end());
    cout << s << '\n';
    return 0;
}