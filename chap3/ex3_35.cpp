#include <iostream>
#include <iterator>
using std::cout;
using std::end;
using std::endl;

int main()
{
    int ar[]{2, 3, 4, 5, 6, 7};
    for (int *p = ar; p != end(ar); ++p)
        *p = 0;
    for (auto i : ar)
        cout << i << ' ';
    cout << endl;
    return 0;
}