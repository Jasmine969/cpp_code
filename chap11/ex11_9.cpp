#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

using std::cout;
using std::find;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::list;
using std::map;
using std::string;
using std::set;

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
    ifstream in("lyrics2.txt");
    unsigned lino = 1;
    string line;
    map<string, list<unsigned>> words_lino;
    while (getline(in, line))
    {
        istringstream stream_words(line);
        string word;
        while (stream_words >> word)
        {
            trans_word(word);
            if (find(words_lino[word].begin(), words_lino[word].end(), lino) != words_lino[word].end()) // 如果word已经在lino一行出现过，就跳过
                continue;
            words_lino[word].push_back(lino);
        }
        ++lino;
    }
    // output
    cout << "Word\t\tLine No.\n";
    for (auto item : words_lino)
    {
        cout << item.first << (item.first.size() == 8 ? "\t" : "\t\t");
        for (auto num : item.second)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}