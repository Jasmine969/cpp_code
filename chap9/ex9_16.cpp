#include <vector>
#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::vector;

int main()
{
    std::ios::sync_with_stdio(false);
    list<int> li1{1,2,3};
    vector<int> vi2{2,3,4};
    vector<int> vi3{1,2,3,4};
    vector<int> v_list(li1.begin(), li1.end());
    cout << (v_list > vi2 ? "v_list > vi2" : "vlist <= vi2") << '\n';
    cout << (v_list > vi3 ? "v_list > vi3" : "v_list <= vi3") << '\n';
    return 0;
}