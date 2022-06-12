#include <iostream>
#include <vector>
#include <numeric>

using std::accumulate;
using std::cout;
using std::vector;

int main()
{
    vector<double> vint{1.1, 2.2, 3.3};
    cout << accumulate(vint.cbegin(), vint.cend(), 0) << '\n';
    return 0;
}