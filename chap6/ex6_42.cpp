#include <iostream>
#include <string>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::size_t;

inline const string makePlural(
    size_t cnt, const string &s1, const string &ending = "s")
{
    return (cnt > 1) ? s1 + ending : s1;
}

int main()
{
    auto suc1 = makePlural(1, "success", "es");
    auto suc3 = makePlural(3, "success", "es");
    auto fail1 = makePlural(1, "failure");
    auto fail3 = makePlural(3, "failure");
    cout << suc1 << endl;
    cout << suc3 << endl;
    cout << fail1 << endl;
    cout << fail3 << endl;
    return 0;
}

