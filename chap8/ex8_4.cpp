#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::ifstream;
using std::getline;
using std::vector;

int main()
{
    vector<string> vs;
    string s;
    ifstream input("article.txt");
    while (getline(input, s))
    {
        vs.push_back(s);
    }
    for (auto n : vs)
    {
        cout << n << '\n';
    }
    return 0;
}