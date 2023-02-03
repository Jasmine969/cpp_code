#include <iostream>
using std::cout;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include "../myfunc.h"

template <typename C>
void printC(const C &container)
{
    using size_type = typename C::size_type;
    size_type sz = container.size(), cnt = 0;
    typename C::const_iterator it = container.cbegin();
    while (cnt != sz)
    {
        cout << *it++ << ' ';
        ++cnt;
    }
    cout << std::endl;
}

int main()
{
    vector<char> vc{'I', 'L', 'o', 'v'};
    printC(vc);
    list<unsigned> lu{3,2,1,5};
    printC(lu);
    cout << std::endl;
    printContainer(vc, '|');
    printContainer(lu);
    return 0;
}