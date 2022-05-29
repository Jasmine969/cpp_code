#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;

void replace_str(string& s, const string& oldVal, const string& newVal)
{
    unsigned old_size = oldVal.size(), new_size = newVal.size();
    unsigned ind = 0;
    while (ind <= s.size() - old_size)
    {
        if (s.substr(ind, old_size) == oldVal)
        {
            s.replace(ind, old_size, newVal);
            ind += new_size;
        }
        else
        {
            ++ind;
        }
    }
}

int main()
{
    string s1("tho"), s2("thru");
    string s3("rabc,abcc,aadbab");
    replace_str(s1, "o", "ough");
    replace_str(s2, "u","ough");
    replace_str(s3, "ab","xxx");
    cout << s1 << '\n';
    cout << s2 << '\n';
    cout << s3 << '\n';
    return 0;
}