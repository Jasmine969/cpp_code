#include <vector>
#include <iostream>
#include <list>

using std::list;
using std::vector;
using std::cout;

int main()
{
    vector<char> vc{'a','b','c','d','e','f','g','h','i'};
    //要逆序拷贝d e f g
    list<char> lc(vc.rbegin() + 2, vc.rbegin() + 6);
    for (char c : lc)
    {
        cout << c << ' ';
    }
    cout << '\n';
    return 0;
}