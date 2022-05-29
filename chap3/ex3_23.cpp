#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec{1, 2, 3, 4, 6, 1, 10, 12, 5, 7};
    for (auto it = ivec.begin(); it != ivec.end(); ++it)
    {
        *it *= 2;
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}