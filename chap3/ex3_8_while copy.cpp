#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Enter a string:" << endl;
    string s;
    cin >> s;
    for (auto &c : s)
        if (ispunct(c))
            c = '\0';
    cout << s << endl;
    return 0;
}