#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::runtime_error;
using std::string;
using std::unordered_map;

unordered_map<string, string> buildMap(ifstream &map_file)
{
    unordered_map<string, string> rules;
    string key, value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
        {
            rules[key] = value.substr(1);
        }
        else
        {
            throw runtime_error("No rule for " + key);
        }
    }
    return rules;
}

const string &transform(const string &word,
                        unordered_map<string, string> &rules)
{
    auto map_it = rules.find(word);
    if (map_it != rules.end())
    {
        return map_it->second;
    }
    return word;
}

void word_transform(ifstream &map_file, ifstream &src)
{
    auto transMap = buildMap(map_file);
    string line;
    while (getline(src, line))
    {
        bool firstWord = true;
        istringstream line_stream(line);
        string word;
        while (line_stream >> word)
        {
            if (firstWord)
            {
                firstWord = false;
            }
            else
            {
                cout << ' ';
            }
            cout << transform(word, transMap);
        }
        cout << '\n';
    }
}

int main()
{
    ifstream map_file("map_table.txt");
    ifstream src("src.txt");
    word_transform(map_file, src);
    return 0;
}