#include <iostream>
#include <cstddef>
#include <iterator>

using std::begin;
using std::end;
using std::cout;
using std::endl;
using std::size_t;

void myPrint(const int i)
{
    cout << i << endl;
}

void myPrint(const int *p, const size_t sz)
{
    for (size_t i = 0; i != sz; ++i)
    {
        cout << *p++ << ' ';
    }
    cout << endl;
}

void myPrint(const int *b, const int *e)
{
    while (b != e)
    {
        cout << *b++ << ' ';
    }
    cout << endl;
}

int main()
{
    int i = 0;
    int j[2] = {0, 1};
    myPrint(i);
    myPrint(j, 2);
    myPrint(begin(j), end(j));
    return 0;
}