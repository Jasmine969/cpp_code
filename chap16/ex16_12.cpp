#include "Blob.h"

int main()
{
    Blob<double> b{1.0, 2.3, 4};
    for (auto it = b.begin(); it != b.end(); ++it)
    {
        cout << *it << '\t';
    }
    cout << '\n';
    return 0;
}