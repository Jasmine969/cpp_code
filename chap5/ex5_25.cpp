#include <iostream>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::overflow_error;
using std::string;

int main()
{
    string s;
    int a = 0, b = 0;
    do
    {
        cout << "Enter two integers: ";
        cin >> a >> b;
        try
        {
            if (b)
            {
                double c = static_cast<double>(a) / b;
                cout << a << '/' << b << " equals " << c << endl;
            }
            else
            {
                throw overflow_error("The divisor cannot be zero!");
            }
        }
        catch (const overflow_error &e)
        {
            std::cerr << e.what() << "\nAgain? Enter yes or no" << endl;
            cin >> s;
        }
    } while (s[0] == 'y');
    return 0;
}