#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    vector<vector<int>> vint{v1, v2, v3, v4, v5};
    vector<vector<string>> vstr{v6, v7};
    int cnt = 1;
    for (auto vi = vint.cbegin(); vi != vint.cend(); ++vi)
        {
            cout << 'v' << cnt << ": ";
            for (auto i = vi -> cbegin(); i != vi -> cend(); ++i)
                cout << *i << ' ';
            cout << endl;
            cout << string(10, '=') << endl;
            ++ cnt;
        }
    for (auto vi = vstr.cbegin(); vi != vstr.cend(); ++vi)
        {
            cout << 'v' << cnt << ": ";
            for (auto i = vi -> cbegin(); i != vi -> end(); ++i)
                cout << *i << ' ';
            cout << endl;
            cout << string(10, '=') << endl;
            ++ cnt;
        }
    return 0;
}