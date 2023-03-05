#include "print_ex53.h"
#include <iostream>
#include "debug_rep.h"

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args &...rest)
{
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(std::cerr, 1, 'c', "foo", -90.1);
    return 0;
}