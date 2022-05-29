#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using std::cin;
using std::string;
using std::vector;
using std::istringstream;
using std::getline;
using std::cout;
using std::ifstream;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    ifstream input("phones.txt");
    string line, word;
    vector <PersonInfo> people;
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
    cout << "Name" << "\t" << "Phones" << "\n";
    for (auto person : people)
    {
        cout << person.name << "\t";
        for (auto phone : person.phones)
        {
            cout << phone << "  ";
        }
        cout << "\n";
    }
    return 0;
}