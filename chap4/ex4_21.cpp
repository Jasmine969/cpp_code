#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v{1,2,3,4,5,6,7};
    for (auto &n : v)
        n = n % 2 ? 2 * n : n;
    for (auto n : v)
        cout << n << ' ';
    cout << endl;
    return 0;
}