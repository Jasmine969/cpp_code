#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> scores{
        42, 65, 95, 100, 39, 67, 95,
        76, 88, 76, 83, 92, 76, 93};
    vector<int> num(11);
    auto beg_num = num.begin();
    for (auto it = scores.cbegin(); it < scores.cend(); ++it)
    {
        ++(*(beg_num+*it/10));
    }
    for (auto n : num)
        cout << n << ' ';
    cout << endl;
    return 0;
}