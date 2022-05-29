#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main()
{
    string s1, s2, judge;
    do
    {
        cout << "Enter the first string:" << endl;
        getline(cin, s1);
        cout << "Enter the second string:" << endl;
        getline(cin, s2);
        cout << "The longer sequence is: " << endl;
        if (s1.size() > s2.size())
        {
            cout << s1 << endl;
        }
        else
        {
            cout << s2 << endl;
        }
        cout << "More? Enter yes or no" << endl;
        cin >> judge;
        cin.ignore(); // 有一个回车在缓冲区，清除之
    } while (judge[0] == 'y');
    return 0;
}