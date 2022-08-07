#include <map>
#include <string>
#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::getline;
using std::istringstream;
using std::multimap;
using std::string;

int main()
{
    multimap<string, string> family;
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
            // family[family_name].push_back(last_name);
            family.insert({family_name, last_name});
        }
        cout << "Continue? (Y/N):  ";
        cin >> if_continue;
        cin.ignore();
    } while (if_continue == 'y' || if_continue == 'Y');
    // 输出结果
    cout << "The family names and last names are as follows:\n";
    cout << "Family name\tLast name\n";
    for (auto item : family)
    {
        cout << item.first << "\t\t" << item.second << '\n';
    }
    return 0;
}