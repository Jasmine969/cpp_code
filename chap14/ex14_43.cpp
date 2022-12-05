#include <numeric>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std::placeholders;
using std::accumulate;
using std::back_inserter;
using std::bind;
using std::cout;
using std::modulus;
using std::set;
using std::transform;
using std::vector;

bool judge(const set<int> &factors, int val)
{
    vector<int> vint;
    transform(factors.begin(), factors.end(),
              back_inserter(vint),
              bind(modulus<int>(), val, _1));
    // 也可以用find_if找到非零数，然后用vint.end()减去它，看是否为零
    // 还可以用count_if找，但比find_if更麻烦一点（见11.3.5节，count比find做得更多）
    return !accumulate(vint.begin(), vint.end(), 0);
}

int main()
{
    set<int> sint{2, 3, 4, 5, 6, 7};
    cout << std::boolalpha << judge(sint, 1680) << '\n';
    return 0;
}