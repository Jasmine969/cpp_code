#include <iostream>

using std::cin;
using std::cout;

int main()
{
    unsigned sz = 5;
    char* cp = new char[sz+1](); // 多一个存放'\0'，值初始化，现在全是'\0'
    char c;
    unsigned i = 0;
    while (i != sz && cin.get(c)) // 使用get使得空白也可以被读入
    {
        cp[i++] = c;
    }
    cout << cp << '\n';
    delete [] cp;
    return 0;
}