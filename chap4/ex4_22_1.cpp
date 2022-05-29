#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int grade = 0;

    cout << "Enter a grade (negative if exit): ";
    while (cin >> grade && grade >= 0)
    {
        cout << (grade > 90 ? "High pass"
        : (grade > 75 ? "Pass"
        : (grade >= 60 ? "Low pass" : "Failed")))<< endl;
        cout << "Enter a grade (negative if exit): ";
    }
    cout << "Bye!" << endl;
    return 0;
}