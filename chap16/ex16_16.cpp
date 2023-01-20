#include "Vec.h"

int main()
{
    Vec<double> dv;
    for (unsigned i = 0; i != 10; ++i)
    {
        dv.push_back(i * 1.2);
    }
    dv.resize(13, -1.1);
    for (auto it = dv.begin(); it != dv.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';
    return 0;
}