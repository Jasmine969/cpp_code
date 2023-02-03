#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>
using std::ostream;

class DebugDelete
{
    ostream &os;
    int i;

public:
    DebugDelete(ostream &o = std::cerr) : os(o) {}
    template <typename T>
    void operator()(T *p)
    {
        os << "Delete a dynamic pointer\n";
        delete (p);
    }
};

#endif