#include <iostream>
#include <string>
#include <set>
#include <map>

using std::cout;
using std::multimap;
using std::multiset;
using std::string;
using std::map;

class Base
{
public:
    int i;

protected:
    int j;

private:
    int k;
};

class Derived : protected Base
{
};

bool compare(const string& lhs, const string& rhs)
{
    return lhs < rhs;
}

int main()
{
    map<string, int, decltype(compare)*> m{compare};
    m.insert({"a", 1});
    m.insert({"b", 2});
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->second << '\n';
    }
    return 0;
}