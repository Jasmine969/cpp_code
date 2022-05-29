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
    for (string::size_type idx = 0; idx < s.size(); ++idx)
        s[idx] = 'X';
    cout << s << endl;
    return 0;
}