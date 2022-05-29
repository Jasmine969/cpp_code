#include <iostream>
#include <string>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;

int main()
{
    string s1;
    cout << "Enter a string:" << endl;
    while (std::getline(cin, s1))
    {
        unsigned int ffCnt = 0;
        unsigned int flCnt = 0;
        unsigned int fiCnt = 0;
        auto iter = begin(s1);
        while (iter != end(s1))
        {
            if (*iter == 'f')
            {
                switch (*(iter + 1))
                {
                case 'f':
                    ++ffCnt;
                    ++iter;
                    break;
                case 'i':
                    ++fiCnt;
                    ++iter;
                    break;
                case 'l':
                    ++flCnt;
                    ++iter;
                    break;
                default:;
                }
            }
            ++iter;
        }
        cout << "ffCnt\t" << ffCnt << endl;
        cout << "fiCnt\t" << fiCnt << endl;
        cout << "flCnt\t" << flCnt << endl;
        cout << "Enter a string:" << endl;
    }
    return 0;
}