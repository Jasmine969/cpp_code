#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char prechar = 0;
    char c = 0;
    int ffCount = 0, fiCount = 0, flCount = 0;
    bool flag_ff = false;
    cout << "Enter a string:" << endl;
    while (cin >> c)
    {
        if (prechar == 'f')
        {
            switch (c)
            {
            case 'f':
                ++ffCount;
                flag_ff = true;
                break;
            case 'i':
                ++fiCount;
                break;
            case 'l':
                ++flCount;
                break;
            default:
                break;
            }
        }
        if (flag_ff)
        {
            prechar = 0;
            flag_ff = false;
        }
        else
            prechar = c;
    }
    cout << "ffCnt\t" << ffCount << endl;
    cout << "fiCnt\t" << fiCount << endl;
    cout << "flCnt\t" << flCount << endl;
    return 0;
}