#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>

using std::cerr;
using std::cin;
using std::cout;
using std::getline;
using std::ifstream;
using std::isdigit;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &s)
{
    for (auto c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

string formatted(string s)
{
    for (unsigned ind = 3; ind < s.size(); ind += 4)
    {
        s.insert(ind, "-");
    }
    return s;
}

int main()
{
    ifstream input("phones.txt");
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(input, line))
    {
        PersonInfo info;
        // istringstream record(line);
        record.str(line); // 把line拷贝到record
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
        // 因为record遇到文件结束符了，所以得复位
        record.clear();
    }
    cout << "Name"
         << "\t"
         << "Phones"
         << "\n";
    for (const auto &person : people)
    {
        ostringstream badNums, validNums;
        for (const auto &phone : person.phones)
        {
            if (valid(phone))
            {
                validNums << "\t" << formatted(phone);
            }
            else
            {
                badNums << "\t" << phone;
            }
        }
        if (badNums.str().empty())
        {
            cout << person.name << validNums.str() << "\n";
        }
        else
        {
            cerr << "Invalid input: " << person.name << "\t" << badNums.str() << "\n";
        }
    }
    return 0;
}