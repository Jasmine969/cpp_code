#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    string s("ab2c3d7R4E6");
    string::size_type pos = 0;
    while (pos != s.size() && (pos = s.find_first_of("0123456789", pos)) != string::npos)
    {
        cout << "index: " << pos << "\t\t"
             << "character:"
             << "\t" << s[pos] << '\n';
        ++pos;
    }
    pos = 0;
    while (pos != s.size() && ((pos = s.find_first_of("qwertyuiopasdfghjklzxcvbnmQAZWSXEDCRFVTGBYHNUJMIKLOP", pos)) != string::npos))
    {
        cout << "index: " << pos << "\t\t"
             << "character:"
             << "\t" << s[pos] << '\n';
        ++pos;
    }
    return 0;
}