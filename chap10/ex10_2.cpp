#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::count;

int main()
{
    string w;
    vector<string> vstr;
    while (cin >> w)
    {
        vstr.push_back(w);
    }
    cout << count(vstr.begin(), vstr.end(), "love") << '\n';
    return 0;
}