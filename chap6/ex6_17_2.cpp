#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void strLower(string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
}

int main()
{
    char c = 'n';
    do
    {
        cout << "Enter a string" << endl;
        string s1;
        cin >> s1;
        strLower(s1);
        cout << s1 << endl;
        cout << "More? y or n" << endl;
        cin >> c;
    } while (c == 'y');
    cout << "Bye!" << endl;
    return 0;
}
