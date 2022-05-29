#include <iostream>
#include <vector>
#include <string>

using std::atoi;
using std::cout;
using std::endl;
using std::size_t;
using std::string;

string *split(string &text)
{
    int i = 0, ar_ind = 0;
    string *ret = new string[5];
#ifndef NDEBUG
    string tmp;
#endif
    while (1)
    {
        ret[ar_ind] += text[i++];
#ifndef NDEBUG
        tmp = ret[ar_ind];
#endif
        if (text[i] == ' ')
        {
            ++ar_ind;
            ++i;
        }
        if (i == text.size() || ar_ind == 5)
        {
            break;
        }
    }
    return ret;
}
typedef string *return_type;
using func_type = return_type(*)(string &);
// string* (*foo2())(string &)
func_type foo2()
{
    return split;
}
int main()
{
    string text = "If You got locked away";
    string* (*foo_main)(string &) = foo2();
    auto ret_p = foo_main(text);
    for (unsigned int i = 0; i != 5; ++i)
    {
        cout << ret_p[i] << endl;
    }
    return 0;
}