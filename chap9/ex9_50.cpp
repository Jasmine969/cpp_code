#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;
using std::stoi;

int main()
{
    vector<string> vstr{"1.1", "2", "3", "4", "5"};
    int sum = 0;
    for (auto s : vstr)
    {
        sum += stoi(s);
    }
    cout << sum << '\n';
    vector<string> vstr2{"1.1", "2", "3", "4", "5"};
    double sum1 = 0;
    for (auto s : vstr2)
    {
        sum1 += stod(s);
    }
    cout << sum1 << '\n';
    return 0;
}