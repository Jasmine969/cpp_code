#include <map>
#include <iostream>

using std::map;
using std::cout;

int main()
{
    map<char, int> m = {{'a', 1}, {'b', 2}};
    map<char, int>::iterator it = m.begin();
    ++it;
    it -> second = 10;
    cout << m['a'] << ' ' << m['b'] << '\n';
    return 0;
}