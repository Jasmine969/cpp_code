#include <deque>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::deque;
using std::getline;
using std::cin;

int main()
{
    string s;
    deque<string> dstr;
    while (getline(cin, s))
    {
        dstr.push_back(s);
    }
    for (auto it = dstr.cbegin(); it != dstr.cend(); ++it)
    {
        cout << *it << '\n';
    }
    return 0;
}