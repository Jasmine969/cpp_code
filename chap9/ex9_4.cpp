#include <vector>
#include <iostream>

using std::cout;
using std::vector;

bool search_vec(vector<int> vi, int n)
{
    for (auto it = vi.cbegin(); it != vi.cend(); ++it)
    {
        if (*it == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> test_v{1,2,4,5,6,7,8};
    cout << std::boolalpha << search_vec(test_v, 3) << ' ' << search_vec(test_v, 4) << ' ' << search_vec(test_v, -1) << '\n';
    return 0;
}