#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    string total, tmp;
    while (getline(cin, tmp))
        total += tmp + " ";
    cout << total << endl;
    return 0;
}