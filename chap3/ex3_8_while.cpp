#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Enter a string:" << endl;
    string s;
    cin >> s;
    string::size_type idx = 0;
    while (idx < s.size())
    {
        s[idx] = 'X';
        ++idx;
    }
    cout << s << endl;
    return 0;
}