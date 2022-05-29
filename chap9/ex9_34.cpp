#include <vector>
#include "../myfunc.h"
#include <string>
#include <windows.h>

using std::string;
using std::vector;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
            {iter = vi.insert(iter, *iter);++iter;}
        ++iter;
        printVec(vi);
        Sleep(1000);
    }
    return 0;
}