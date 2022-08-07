#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::ifstream;
using std::map;
using std::set;
using std::string;

void trans_word(string &s)
{
    set<char> exclu_punc{',', '.', ':', '\"', '\'', ';', '?'};
    auto iter = s.begin();
    while (iter != s.end())
    {
        if (iter + 1 == s.end() // 是尾元素了，看看是否是标点
            && exclu_punc.find(*iter) != exclu_punc.end())
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
    ifstream in("lyrics.txt");
    string word;
    map<string, unsigned> wc;
    set<string> exclude{"the", "and", "or", "The", "And", "Or"};
    while (in >> word)
    {
        trans_word(word);
        // 这个词在exclude中，所以不参与统计
        if (exclude.find(word) != exclude.end())
            continue;
        auto res = wc.insert({word, 1});
        if (!res.second) // word已经在wc中了
        {
            ++res.first->second;
        }
    }
    for (auto &p : wc)
    {
        cout << "\"" << p.first << "\" occurs " << p.second << (p.second == 1 ? " time" : " times") << "\n";
    }
    return 0;
}