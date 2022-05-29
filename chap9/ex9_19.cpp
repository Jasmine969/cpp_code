#include <list>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::list;
using std::getline;
using std::cin;

int main()
{
    string s;
    list<string> lstr;
    while (getline(cin, s))
    {
        lstr.push_back(s);
    }
    for (auto it = lstr.cbegin(); it != lstr.cend(); ++it)
    {
        cout << *it << '\n';
    }
    return 0;
}