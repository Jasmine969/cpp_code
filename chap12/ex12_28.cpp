#include <memory>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>

using namespace std;

// global variable
vector<string> text;
map<string, set<unsigned>> wordsPosMap;
map<string, unsigned> wordCount;

void build_map(ifstream &infile)
{
    string line;
    unsigned lino = 0;
    while (getline(infile, line))
    {
        ++lino;
        text.push_back(line);
        istringstream line_stream(line);
        string word;
        while (line_stream >> word)
        {
            wordsPosMap[word].insert(lino);
            ++wordCount[word];
        }
    }
}

void query(ostream &os, const string &word)
{
    /* 虽然不存在的word有可能会被添加到wordCount里，但这个word的Count也是0，
    wordMapPos的set也是空集，所以不会影响结果正确性。
    从防止开辟新内存的角度，可以加一个if-else防止添加不存在的单词。 */
    map<string, unsigned>::iterator loc = wordCount.find(word);
    if (loc == wordCount.end())
    {
        os << word << " occurs 0 time.\n";
    }
    else
    {
        os << word << " occurs " << loc->second
           << (loc->second > 1 ? " times\n" : " time\n");
        for (const unsigned n : wordsPosMap[word])
        {
            os << "\t(line " << n << ") " << text[n - 1] << "\n";
        }
    }
}

void runQueries(ifstream &infile)
{
    build_map(infile);
    string s;
    while (true)
    {
        cout << "enter word to look for, or q to quit\n";
        if (!(cin >> s) || s == "q")
            break;
        query(cout, s);
    }
}

int main()
{
    ifstream in("lyrics2.txt");
    runQueries(in);
    return 0;
}