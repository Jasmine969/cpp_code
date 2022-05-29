#include <iostream>

using std::cout;
using std::endl;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
int (*arrPtr(int i))
{
    return (i%2)? odd : even;
}

int main()
{
    int *p = odd;
    auto ret = arrPtr(1);
    // for (unsigned int i = 0; i != 5; ++i)
        // cout << (*ret)[i] << ' ';
    // cout <<endl;
}