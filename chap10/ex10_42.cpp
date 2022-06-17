#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::list;
using std::string;

void elimDup(list<string> &lst)
{
    lst.sort();
    lst.unique();
}

int main()
{
    list<string> vstr{"the", "red", "fox", "jumps",
                      "over", "the", "red", "dog"};
    elimDup(vstr);
    for (auto s : vstr)
    {
        cout << s << " ";
    }
    cout << '\n';
    return 0;
}