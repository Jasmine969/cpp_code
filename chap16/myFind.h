#ifndef MYFIND_H
#define MYFIND_H

template<typename Iterator, typename T>
Iterator myFind(Iterator beg, Iterator end, T val)
{
    for (Iterator it = beg; it != end; ++it)
    {
        if (*it == val)
            return it;
    }
    return end;
}

#endif