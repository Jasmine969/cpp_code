#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a = 0, b = 0;
    cout << "Enter two integers: ";
    cin >> a >> b;
    double c = static_cast<double>(a) / b;
    cout << a << '/' << b << " equals " << c << endl;
    return 0;
}