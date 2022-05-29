#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v;
    int i = 0;
    cout << "Enter an interger: ";
    while (cin >> i)
    {
        v.push_back(i);
        if (i != 42)
            cout << "Enter an interger: ";
        else
            break;
    }
    for (const auto j : v)
        cout << j << ' ';
    cout << endl;
    return 0;
}