#include <vector>
#include <iostream>

using std::cout;
using std::vector;

int main()
{
    std::ios::sync_with_stdio(false);
    vector<int> vi1{1,2,3};
    vector<int> vi2{2,3,4};
    vector<int> vi3{1,2,3,4};
    cout << (vi1 == vi2 ? "vi1 == vi2" : "vi1 != vi2") << '\n';
    cout << (vi2 == vi3 ? "vi2 == vi3" : "vi2 != vi3") << '\n';
    return 0;
}