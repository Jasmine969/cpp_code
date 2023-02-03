#include <iostream>
using std::cout;

#include <list>
using std::list;

#include <array>
using std::array;

template <typename C>
void printC(const C &container)
{
    using it_type = typename C::const_iterator;
    for (it_type it = container.cbegin(); it != container.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';
}

int main()
{
    list<double> ld{1.1, 2.2, 5.3};
    printC(ld);
    array<char,5> ac{'z', 'Y', 'j', 'f', 'Q'};
    printC(ac);
    return 0;
}