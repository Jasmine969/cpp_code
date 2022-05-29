#include <string>
#include <iostream>

using std::string;
using std::cout;

string add_prefix_suffix(string name, const string& prefix, const string& suffix)
{
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
    return name;
}
int main()
{
    string name1 = "Mike";
    string new_name1 = add_prefix_suffix(name1, "Mr", "Ⅲ");
    cout << new_name1 << '\n';
    return 0;
}