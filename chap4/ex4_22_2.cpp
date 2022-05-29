#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    int grade = 0;
    cout << "Enter a grade (negative if exit): ";
    while (cin >> grade && grade >= 0)
    {
        if (grade > 90)
            cout << "High pass" << endl;
        else
            cout << (grade > 75 ? "Pass" : (grade >= 60 ? "Low pass" : "Failed")) << endl;
        cout << "Enter a grade (negative if exit): ";
    }
    cout << "Bye!" << endl;
    return 0;
}