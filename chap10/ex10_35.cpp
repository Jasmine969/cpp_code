#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main()
{
    vector<int> vi{1,2,3,4,5};
    for (auto iter = vi.end(); iter != vi.begin();)
    {
        cout << *(--iter) << ' ';
    }
    cout << '\n';
    return 0;
}