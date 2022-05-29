#include <iostream>

using std::cout;
using std::endl;

int fact(int n)
{
    int ret = 1;
    while (n > 0)
    {
        ret *= n--;
    }
    return ret;
}
int main()
{
    cout << fact(6) << endl;
}