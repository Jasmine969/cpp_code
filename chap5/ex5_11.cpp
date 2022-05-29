#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int main()
{
    int vCnt = 0;
    int spaceCnt = 0;
    int tableCnt = 0;
    int nCnt = 0;
    string s;
    vector<string> svec;
    cout << "Enter the text:" << endl;
    char c;
    // while (getline(cin, s))
    // {
    //     svec.push_back(s);   
    // }
    // for (auto lne : svec)
    //     for (auto c : lne)
    while (cin >> c)
        {
            c = std::tolower(c);
            switch (c)
            {
            case 'a': case 'e': case 'i': 
            case 'o': case 'u':
                ++vCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tableCnt;
                break;
            case '\n':
                ++nCnt;
                break;
            default:;
            }
        }
    cout << "vowel:\t\t" << vCnt << endl;
    cout << "space:\t\t" << spaceCnt << endl;
    cout << "table:\t\t" << tableCnt << endl;
    cout << "newline:\t" << nCnt << endl;
    return 0;
}