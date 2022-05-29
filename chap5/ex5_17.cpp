#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1{0, 1, 1, 2};
    vector<int> v2{0, 1, 1, 2, 3, 5, 8};
    if (v1.size() < v2.size())
    {
        vector<int> tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
    // 现在v1是长向量
    for (int i = 0; i < v2.size(); ++i)
    {
        if (v1[i] != v2[i])
        {
            cout << "No" << endl;
            return -1;
        }
    }
    cout << "Yes" << endl;
    return 0;
}