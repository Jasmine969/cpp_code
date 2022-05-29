#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;

int main()
{
    vector<char> vc{'h','E','l','l','o',',',' ','w','o','r','l','d'};
    // string s(vc.begin(), vc.end());
    string s(vc.data(), vc.size());
    cout << s << '\n';
    return 0;
}