#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::count_if;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> v{"123", "12345a", "12", "1234567", "123456", "12", "12345", "123"};
    unsigned cnt = count_if(v.begin(), v.end(),
    [] (string s) {return s.size() >= 6;});
    cout << cnt << '\n';
    return 0;
}