#include <algorithm>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::count;

int main()
{
    int i;
    vector<int> vint;
    while (cin >> i)
    {
        vint.push_back(i);
    }
    cout << count(vint.begin(), vint.end(), 3) << '\n';
    return 0;
}