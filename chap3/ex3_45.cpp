#include <iostream>
#include <iterator>

using std::cout;
using std::end;
using std::endl;

int main()
{
    int ar[3][4] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12};
    for (auto row = ar; row < end(ar); ++row)
    {
        for (auto col = *row; col < end(*row); ++col)
            cout << *col << ' ';
        cout << endl;
    }
    return 0;
}