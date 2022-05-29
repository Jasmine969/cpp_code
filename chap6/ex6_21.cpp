#include <iostream>

using std::cout;
using std::endl;

int myCompare(const int a, const int *const pb)
{
    if (a >= *pb)
        return a;
    else
        return *pb;
}

int main()
{
    int a = 1, b = 2, c = 2, d = 3;
    int ar[5] = {7,2,3,6,7};
    cout << myCompare(a, &b) << endl;
    cout << myCompare(c, &b) << endl;
    cout << myCompare(d, &b) << endl;
    cout << myCompare(d, ar) << endl;
    return 0;
}