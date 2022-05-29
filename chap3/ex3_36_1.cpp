#include <iostream>
#include <iterator>

using std::cout;
using std::end;
using std::endl;

int main()
{
    int ar[]{1, 2, 4, 5, 6};
    int br[]{2, 3};
    int cr[]{1, 2, 3, 4, 5};
    int dr[]{1, 2, 3, 4, 5};
    if (end(ar) - ar != end(br) - br)
    {
        cout << "Unequal: length" << endl;
        return 0;
    }
    int *a = ar;
    int *b = br;
    while (a != end(ar))
    {
        if (*a != *b)
        {
            cout << "Unequal: value" << endl;
            return 0;
        }
        ++a;
        ++b;
    }
    cout << "Equal" << endl;
    return 0;
}