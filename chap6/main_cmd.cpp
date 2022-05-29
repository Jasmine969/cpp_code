#include <iostream>
#include <string>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

/* 
如果命令行输入 .\main_cmd -n 9
则主程序运行9次
*/
int main(int argc, char *argv[])
{
    int m = 0;
    for (size_t i = 0; i != argc - 1; ++i)
    {
        // 必须先转化成string对象，否则字符指针无法和 "-n" 比较
        string s = argv[i];
        // 如果检测到 -n 且后面跟着一个数，则获取之并退出循环
        if (s == "-n" && (m = std::atoi(argv[i+1])))
        {
            break;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        cout << "I love you!" << endl;
    }
    return 0;
}