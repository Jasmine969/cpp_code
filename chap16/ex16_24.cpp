#include <list>
#include <deque>
#include "../myfunc.h"
#include "Blob.h"

extern template class Blob<char>;

int main()
{
    const std::list<char> lc{'I', 'a', 'M', 'z'};
    std::deque<long> dl{-1, 2, 3, 10};
    Blob<char> b1(lc.begin(), lc.end());
    Blob<int> b2(dl.begin(), dl.end());
    printContainer(b1);
    printContainer(b2);
    printContainer(lc);
    return 0;
}