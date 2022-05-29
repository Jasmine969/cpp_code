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
    for (decltype(vint.size()) i = 0; i < 5; ++i)
    {
        cout << 'v' << i << ':' << endl;
        cout << "Size: " << vint[i].size() << endl;
        for (auto j : vint[i])
            cout << j << ' ';
        cout << '\n'
             << string(15, '=') << endl;
    }
    cout << "Now string: " << endl;
    for (decltype(vint.size()) i = 0; i < 2; ++i)
    {
        cout << 'v' << i << ':' << endl;
        cout << "Size: " << vstr[i].size() << endl;
        for (auto j : vstr[i])
            cout << j << ' ';
        cout << '\n'
             << string(15, '=') << endl;
    }    

    return 0;
}