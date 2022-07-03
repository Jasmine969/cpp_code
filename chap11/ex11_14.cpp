#include <utility>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::find_if;
using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
    map<string, vector<pair<string, string>>> families;
    string option, surname, lastname, birthday;
    cout << "Enter the option (s, l, b or their combination): ";
    while (cin >> option && option != "e" && option != "exit")
    {
        if (option == "s") // add a surname
        {
            cout << "Enter the surname: ";
            cin >> surname;
            families[surname] = vector<pair<string, string>>();
        }
        else if (option == "lb" || option == "slb")
        {
            cout << "Enter the surname: ";
            cin >> surname;
            cout << "Enter the last name: ";
            cin >> lastname;
            cout << "Enter the birthday: ";
            cin >> birthday;
            auto has_lastname = find_if(families[surname].begin(),
                                        families[surname].end(),
                                        [lastname](pair<string, string> pr)
                                        { return pr.first == lastname; });
            auto has_birthday = find_if(families[surname].begin(),
                                        families[surname].end(),
                                        [birthday](pair<string, string> pr)
                                        { return pr.second == birthday; });
            if (has_lastname == families[surname].end() && has_birthday == families[surname].end()) // 原来没有
            {
                families[surname].emplace_back(lastname, birthday);
            }
            else if (has_lastname != families[surname].end() && has_birthday == families[surname].end()) // 有surname没有birthday
            {
                (*has_lastname).second = birthday;
            }
            else // 有birthday没有surname或者两个都有
            {
                (*has_birthday).first = lastname;
            }
        }
        else if (option == "l" || option == "sl")
        // 只更新last name，视为新增一人
        {
            cout << "Enter the surname: ";
            cin >> surname;
            cout << "Enter the last name: ";
            cin >> lastname;
            families[surname].emplace_back(lastname, "N/A");
        }
        else if (option == "b" || option == "sb")
        // 只更新birthday，视为新增一人
        {
            cout << "Enter the surname: ";
            cin >> surname;
            cout << "Enter the birthday: ";
            cin >> birthday;
            families[surname].emplace_back("", birthday);
        }
        else
        {
            cout << "Invalid option! Enter again: ";
            continue;
        }
        cout << "Done! Enter the option (s, l, b, their combination, or exit/e): ";
    }
    // output
    cout << "families are as follows:\n";
    cout << "Surname\tLast name\tBirthday\n";
    for (auto family : families)
    {
        for (auto last_birth:family.second)
        {
            cout << family.first << "\t" << last_birth.first << "\t" << last_birth.second << "\n";
        }
        cout << "\n" << string(10, '-') << "\n";
    }
    return 0;
}