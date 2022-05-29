#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0, val = 0;
    while (++val, sum+=val, val < 10)
        ;
    cout << sum << endl;
    return 0;
}