#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    char judge = 'y';
    while (judge == 'y')
    {
        cout << "Enter four numbers: ";
        cin >> a >> b >> c >> d;
        if (a > b && b > c && c > d)
            cout << "Right!" << endl;
        else
            cout << "Wrong!" << endl;
        cout << "Continue (y) or exit (n)? ";
        cin >> judge;
    }
    cout << "Bye!" << endl;
    return 0;
}