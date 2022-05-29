#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int a = 0, b = 0;
    cout << "Enter two integers: ";
    cin >> a >> b;
    if (b)
    {
        double c = static_cast<double>(a) / b;
        cout << a << '/' << b << " equals " << c << endl;
    }
    else
    {
        throw std::overflow_error("The divisor cannot be zero!");
    }
    return 0;
}