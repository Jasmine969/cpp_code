#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int ar[] = {2,4,6,8};
    vector<int> ivec(begin(ar), end(ar));
    for (auto i : ivec)
        cout << i << ' ';
    cout << endl;
    return 0;
}