#include <iostream>

using std::cin;
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
    char c;
    do
    {
        cout << "Enter an integer: ";
        int i = 0;
        cin >> i;
        cout << "The factorial of " << i << " is " << fact(i) << endl;
        cout << "More? y or n: ";
        cin >> c;
    } while (c == 'y');
}