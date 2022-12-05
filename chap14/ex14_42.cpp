#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std::placeholders;
using std::bind;
using std::count_if;
using std::cout;
using std::find_if;
using std::transform;
using std::greater;
using std::string;
using std::vector;
using std::bind;

int main()
{
    // greater than 1024
    vector<int> vint{1, 1024, 2, 1025, 1036, 1029, 44};
    cout << count_if(
                vint.begin(), vint.end(),
                bind(std::greater<int>(), _1, 1024))
         << '\n';
    // 1st string neq "pooh"
    vector<string> svec{"pooh", "pooh", "POOH", "pooh",
                        "GOOD", "I", "LOVE", "YOU"};
    cout << *find_if(svec.begin(), svec.end(),
                     bind(std::not_equal_to<string>(), _1, "pooh"))
         << '\n';
    // all elements multiplied by 2
    transform(vint.begin(), vint.end(), vint.begin(),
                bind(std::multiplies<int>(), _1, 2));
    std::ostream_iterator<int> oit(cout, " ");
    std::copy(vint.begin(), vint.end(), oit);
    cout << '\n';
    return 0;
}