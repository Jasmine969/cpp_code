#include <vector>
#include <iostream>

using std::cout;
using std::vector;

vector<int>::const_iterator search_vec(vector<int>& vi, int n)
{
    auto it = vi.cbegin();
    for (; it != vi.cend(); ++it)
    {
        if (*it == n)
        {
            return it;
        }
    }
    return it;
}

int main()
{
    vector<int> test_v{1,2,4,5,6,7,8};
    auto iter = search_vec(test_v, 2);
    if (iter == test_v.cend())
    {
        cout << "Not found\n";
    }
    else
    {
        cout << "Found the number: " << *iter << "\n"; 
    }
    cout << (iter - test_v.cbegin()) << "\n";
    return 0;
}