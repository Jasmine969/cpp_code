#include <iostream>
#include <vector>
#include <numeric>

using std::cout;
using std::vector;
using std::accumulate;

int main()
{
    vector<int> vint{12,3,4,5,6};
    cout << accumulate(vint.cbegin(), vint.cend(), 0) << '\n';
    return 0;
}