#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using std::string;
using std::ostream_iterator;
using std::copy;
using std::set;
using std::cout;
using std::swap;

void trans_word(string& s)
{
    set<char> exclu_punc{',','.',':','\"','\'',';'};
    auto iter = s.begin();
    while (iter != s.end())
    {
        if (exclu_punc.find(*iter) != exclu_punc.end())
        {
            iter = s.erase(iter);
        }
        else
        {
            *iter = tolower(*iter);
            ++iter;
        }
    }
}

int main()
{
    string s("Word,");
    trans_word(s);
    cout << s << '\n';
    return 0;
}