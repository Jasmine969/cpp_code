#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec{1, 3, 5, 7};
    unsigned sz = ivec.size();
    int ar[sz] = {};
    for (size_t i = 0; i < sz; ++i)
        ar[i] = ivec[i];
    for (auto i : ar)
        cout << i << ' ';
    cout << endl;
    return 0;
}