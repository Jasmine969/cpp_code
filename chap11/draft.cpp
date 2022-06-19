#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>

using std::list;
using std::string;
using std::ostream_iterator;
using std::copy;
using std::set;
using std::cout;
using std::swap;
using std::find;
using my_fun = bool (*)(const string&);
typedef bool(*fun)(const string&);
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

string::size_type sumLength(const string&, const string&);

auto getFcn(const string&) -> decltype(sumLength)*;

int main()
{
    list<int> li{10,20,30,40,50};
    find(li.begin(), li.end(), 20);
    return 0;
}