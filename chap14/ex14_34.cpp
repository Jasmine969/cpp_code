#include <iostream>

using std::cout;

struct IfThenElse
{
    int operator()(int i, int j, int k)
    {
        return (i > 0) ? j : k;
    }
};

int main()
{
    auto x = IfThenElse();
    cout << x(1, 2, 3) << '\n';
    cout << IfThenElse()(-1, 2, 3) << '\n';
    return 0;
}