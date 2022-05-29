#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int grade = 0;
    cout << "Enter a score: ";
    while (cin >> grade && grade >= 0)
    {
        int n_unit = grade % 10;
        cout << (grade == 100 ? "A++"
         : grade < 60 ? "F"
         : string(1,static_cast<char>(74 - grade / 10))
         + (n_unit > 6 ? '+' 
         : n_unit < 4 ? '-' : '\0'));
        cout << endl << "Enter a score: ";
    }
    cout << "Bye" << endl;
    return 0;
}