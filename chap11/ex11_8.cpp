#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::find;
using std::copy;
using std::ostream_iterator;

int main()
{
    vector<string> vstr;
    string word;
    while (cin >> word)
    {
        auto iter = find(vstr.begin(), vstr.end(), word);
        if (iter == vstr.end())
        {
            vstr.push_back(word);
        }
    }
    ostream_iterator<string> out_iter(cout, " ");
    copy(vstr.begin(), vstr.end(), out_iter);
    return 0;
}