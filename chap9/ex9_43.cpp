#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;

void erase_insert(string& s, const string& oldVal, const string& newVal)
{
    unsigned old_size = oldVal.size(), new_size = newVal.size();
    auto it = s.begin();
    while (it != s.end() + 1 - old_size)
    {
        if (string(it, it + old_size) == oldVal)
        {
            it = s.erase(it, it + old_size);
            it = s.insert(it, newVal.begin(), newVal.end());
            it += new_size;
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    string s1("tho"), s2("thru");
    erase_insert(s1, "o", "ough");
    erase_insert(s2, "u","ough");
    cout << s1 << '\n';
    cout << s2 << '\n';
    return 0;
}