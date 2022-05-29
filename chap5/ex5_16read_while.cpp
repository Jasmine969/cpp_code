/* 用while读取文件中的字母，统计有多少个元音字母和非元音字母*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char c;
    int vowCnt = 0, nonCnt = 0;
    while (cin >> c)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            switch (c)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowCnt;
                break;
            default:
                ++nonCnt;
                break;
            }
        }
    }
    cout << "元音字母有" << vowCnt << "个，非元音字母有" << nonCnt << "个。";
    return 0;
}