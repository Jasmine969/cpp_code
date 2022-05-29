#include <iostream>

using std::cout;
using std::endl;

int add(int x1, int x2)
{
    static unsigned int cnt;
    cout << x1 << '+' << x2 << '=' << x1 + x2 << endl;
    return cnt++;
}

int main()
{
    cout << add(3, 4) << endl;
    cout << add(4, 2) << endl;
    return 0;
}