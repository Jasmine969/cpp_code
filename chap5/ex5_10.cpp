#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    int vCnt = 0;
    string s;
    cout << "Enter the text:" << endl;
    getline(cin, s);
    for (auto c : s)
    {
        c = std::tolower(c);
        switch (c)
        {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            ++vCnt;
            break;
        default:
            ;
        }
    }
    cout << vCnt << endl;
    return 0;
}