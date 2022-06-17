#include <iostream>
#include <map>
#include <set>
#include <string>

using std::cout;
using std::map;
using std::set;
using std::string;
using std::cin;

int main()
{
    string word;
    map<string, unsigned> wc;
    set<string> exclude {"the", "and", "or", "The", "And", "Or"};
    while (cin >> word)
    {
        // 这个词在exclude中，所以不参与统计
        if (exclude.find(word) != exclude.end()) 
            continue;
        ++wc[word];
    }
    for (auto &p : wc)
    {
        cout << "\"" << p.first << "\" occurs " << p.second << (p.second == 1 ? " time" : " times") << "\n";
    }
    return 0;
}