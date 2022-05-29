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
    if (line1 == line2)
        cout << "Equal" << endl;
    else
    {
        cout << "Not equal" << endl;
        if (line1 > line2)
            cout << line1 << endl;
        else
            cout << line2 << endl;
    }
    return 0;
}