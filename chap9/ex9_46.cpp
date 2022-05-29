#include <string>
#include <iostream>

using std::string;
using std::cout;

string add_prefix_suffix(string name, const string& prefix, const string& suffix)
{
    name.insert(0, prefix + " ").insert(name.size(), " " + suffix);
    return name;
}
int main()
{
    string name1 = "Mike";
    string new_name1 = add_prefix_suffix(name1, "Mr", "Ⅲ");
    cout << new_name1 << '\n';
    return 0;
}