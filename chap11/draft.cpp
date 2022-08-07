#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>
#include <utility>
#include <vector>

using std::copy;
using std::cout;
using std::find;
using std::list;
using std::make_pair;
using std::map;
using std::multimap;
using std::ostream_iterator;
using std::pair;
using std::set;
using std::string;
using std::swap;
using std::vector;

void trans_word(string &s)
{
    set<char> exclu_punc{',', '.', ':', '\"', '\'', ';'};
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

string::size_type sumLength(const string &, const string &);

auto comp_pair = [](pair<int, char> p1, pair<int, char> p2)
{ return (p1.first < p2.first) || (!(p2.first < p1.first) && (p1.second < p2.second)); };

pair<int, char> fun() { return {}; };

int main()
{
    map<char, int> m{{'a',1},{'b',2},{'d',44},{'e',5}};
    auto ret = m.equal_range('c');
    cout << ret.first->first << ' ' << ret.second->first << '\n';
    cout << m.at('b') << '\n';
    return 0;
}
