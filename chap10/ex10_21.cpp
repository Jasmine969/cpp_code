#include <iostream>

using std::cout;

int main()
{
    int i = 10;
    auto f = [i] () mutable -> bool
    {
        if (i > 0)
        {
            --i; return false;
        }
        else
        {
            return true;
        }
    };
    cout << std::boolalpha;
    for (int j = 1; j != 20; ++j)
    {
        cout << j << '\t' << f() << '\n';
    }
    return 0;
}