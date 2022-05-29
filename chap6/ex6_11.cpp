#include <iostream>

using std::cout;
using std::endl;

void reset(int &n)
{
    n++;
}
int main()
{
    int m = 10;
    reset(m);
    cout << m << endl;
    return 0;
}