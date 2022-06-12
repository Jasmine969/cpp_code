#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using std::vector;
using std::cout;
using std::string;
using std::bind;
using std::find_if;
using namespace std::placeholders;

bool checkSize(const string& s, int val)
{
    // 无符号不能直接于有符号比较，比较前应该先把unsigned转成int
    return val > static_cast<int>(s.size());
}



int main()
{
    string s("hello");
    vector<int> vi{-3,-1,3,5,7,9};
    auto gt_first = find_if(vi.cbegin(), vi.cend(),
    bind(checkSize, s, _1));
    cout << "The first integer greater than the string length is " << *gt_first << ".\n";
    return 0;
}