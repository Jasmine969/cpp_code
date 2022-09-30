#include "HasPtr_ex31.h"
#include <vector>
#include <string>
#include <algorithm>

using std::sort;
using std::string;
using std::swap;
using std::vector;

int main()
{
    vector<HasPtr> vhp{"I", "love", "you", "so", "much",
                       "I", "love", "you", "so", "much",
                       "I", "love", "you", "so", "much",
                       "I"};
    sort(vhp.begin(), vhp.end());
    for (auto hp : vhp)
    {
        cout << hp.get_str() << "\n";
    }
    return 0;
}