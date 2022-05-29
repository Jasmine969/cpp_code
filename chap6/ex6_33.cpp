#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


void printVec(
    vector<int>::const_iterator it,
    vector<int>::const_iterator vend)
{
    if (it != vend)
    {
        cout << *it << endl;
        printVec(++it, vend);
    }
}

int main()
{
    vector<int> a = {1,2,3,4,5};
    printVec(a.cbegin(), a.cend());
    return 0;
}