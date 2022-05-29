#include <iostream>
#include <vector>

#define NDEBUG

using std::cout;
using std::endl;
using std::vector;


void printVec(
    vector<int> v,
    vector<int>::const_iterator it,
    vector<int>::const_iterator vend)
{
    if (it != vend)
    {
        #ifndef NDEBUG
        cout << sizeof(v) << endl;
        #endif
        cout << *it << endl;
        printVec(v, ++it, vend);
    }
}

int main()
{
    vector<int> a = {1,2,3,4,5};
    printVec(a, a.cbegin(), a.cend());
    return 0;
}