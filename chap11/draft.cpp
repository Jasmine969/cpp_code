#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>
#include <utility>

using std::pair;
using std::make_pair;
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
    pair<int, char> p{3, 'c'};
    pair<int, char> p1{3, 'b'};
    pair<int, char> p2{4, 'd'};
    cout << std::boolalpha << (p < p1) << ' ' << (p < p2) << ' ' << (p1 < p2) << '\n';
    return 0;
}