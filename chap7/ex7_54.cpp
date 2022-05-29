#include <type_traits>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::vector;
using std::endl;

struct Data
{
    int val;
    vector<int> v;
    // string s;
};

int main()
{
    cout << std::boolalpha;Data d;
    cout << std::is_literal_type<Data>::value << endl;
    cout <<std::is_integral<int>::value << endl;
    return 0;
}