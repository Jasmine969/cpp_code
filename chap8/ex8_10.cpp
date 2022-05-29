#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::runtime_error;
using std::vector;
using std::string;
using std::istringstream;
using std::getline;
using std::cin;
using std::cout;
using std::ifstream;

int main()
{
    vector<string> vstr;
    string s1;
    ifstream input("article.txt");
    while (getline(input, s1))
    {
        vstr.push_back(s1);
    }
    input.close();
    for (auto line : vstr)
    {
        istringstream iss(line);
        if (!iss)
        {
            throw runtime_error("Unable to read the line!");
        }
        string word;
        while (iss >> word)
        {
            cout << word << "***";
        }
        cout << "=======" << "\n";
    }
    return 0;
}