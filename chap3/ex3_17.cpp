#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

int main()
{
    vector<string> v1;
    string word;
    while (cin >> word)
        v1.push_back(word);
    for (string &w : v1)
        for (auto &c : w)
            c = toupper(c);
    for (string w : v1)
        cout << w << endl;
    return 0;
}