#include <iostream>
#include <iterator>

using std::end;
using std::cout;
using std::endl;

int main()
{
    int ar[3][4] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12};
    for (int (*row)[4] = ar; row < end(ar); ++row)
    {
        for (int *col = *row; col < end(*row); ++col)
            cout << *col << ' ';
        cout << endl;
    }
    return 0;
}