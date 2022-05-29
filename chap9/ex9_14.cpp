#include <list>
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::list;
using std::string;
using std::vector;

int main()
{
    list<const char*> lch{"If", "YOu", "Got"};
    vector<string> vstr;
    vstr.assign(lch.cbegin(), lch.cend());
    for (auto s : vstr)
    {
        cout << s << ' ';
    }
    cout << '\n';
    cout << vstr.capacity();
    return 0;
}