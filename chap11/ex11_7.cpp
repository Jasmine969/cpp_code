#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using std::cin;
using std::copy;
using std::cout;
using std::getline;
using std::istringstream;
using std::map;
using std::ostream_iterator;
using std::string;
using std::vector;

int main()
{
    map<string, vector<string>> family;
    char if_continue = 'y';
    string family_name, last_names;
    do
    {
        cout << "Family name: ";
        getline(cin, family_name);
        cout << "Last name(s) (split by ';'):  ";
        getline(cin, last_names); // 读取所有名
        istringstream last_stream(last_names);
        string last_name;
        while (getline(last_stream, last_name, ';'))
        { // 删除名前的空格
            while (last_name[0] == ' ')
            {
                last_name.erase(0, 1);
            }
            family[family_name].push_back(last_name);
        }
        cout << "Continue? (Y/N):  ";
        cin >> if_continue;
        cin.ignore();
    } while (if_continue == 'y' || if_continue == 'Y');
    // 输出结果
    cout << "The family names and last names are as follows:\n";
    cout << "Family Name" << '\t' << "Last name\n";
    ostream_iterator<string> out_iter(cout, "   ");
    for (auto item : family)
    {
        cout << item.first << "\t\t";
        copy(item.second.begin(), item.second.end(), out_iter);
        cout << '\n';
    }
    return 0;
}