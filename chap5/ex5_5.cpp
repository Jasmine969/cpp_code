#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int grade = 0;
    cout << "Enter a score: ";
    while (cin >> grade && grade >= 0)
    {
        if (grade == 100)
        {
            cout << "A++" << endl;
        }
        else if (grade < 60)
        {
            cout << "F" << endl;
        }
        else
        {
            cout << static_cast<char>(74 - grade / 10);
            if (grade % 10 < 4)
            {
                cout << '-' << endl;
            }
            else if (grade % 10 > 6)
            {
                cout << '+' << endl;
            }
            else
            {
                cout << endl;
            }
        }
        cout << "Enter a score: ";
    }
    cout << "Bye" << endl;
    return 0;
}