#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vint{1, 2, 3, 4};
    vector<int> vjnt{2, 3, 4, 5};
    vector<int> vknt{1, 2};
    vector<int> vlnt{1, 2, 3, 4};
    if (vint != vlnt)
    {
        cout << "Unequal" << endl;
        return 0;
    }
    cout << "Equal" << endl;
    return 0;
}