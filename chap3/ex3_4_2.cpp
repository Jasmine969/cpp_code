#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    string line1, line2;
    cout << "Enter two strings" << endl;
    getline(cin, line1);
    getline(cin, line2);
    // unsigned int len1 = 0, len2 = 0;
    // len1 = line1.size();
    // len2 = line2.size();
    auto len1 = line1.size();
    auto len2 = line2.size();
    if (len1 == len2)
        cout << "Equal" << endl;
    else
    {
        cout << "Not equal" << endl;
        if (len1 > len2)
            cout << line1 << endl;
        else
            cout << line2 << endl;
    }
    return 0;
}