#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool haveUpper(const string &s)
{
    for (auto c : s)
    {
        if (isupper(c))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char c = 'n';
    do
    {
        cout << "Enter a string" << endl;
        string s1;
        cin >> s1;
        if (haveUpper(s1))
        {
            cout << "Have uppercase" << endl;
        }
        else
        {
            cout << "No uppercase" << endl;
        }
        cout << "More? y or n" << endl;
        cin >> c;
    } while (c == 'y');
    cout << "Bye!" << endl;
    return 0;
}