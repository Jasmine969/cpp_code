#include "debug_rep_ex65.h"
#include <cstring>

int main()
{
    debug_rep("yellow"); // const char *
    auto p = new char;
    std::strcpy(p, "red");
    debug_rep(p); // char *
    return 0;
}