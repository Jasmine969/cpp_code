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
        if (c == 'a')
        {
            ++vCnt;
        }
        else if (c == 'e')
        {
            ++vCnt;
        }
        else if (c == 'i')
        {
            ++vCnt;
        }
        else if (c == 'o')
        {
            ++vCnt;
        }
        else if (c == 'u')
        {
            ++vCnt;
        }
    }
    cout << vCnt << endl;
    return 0;
}