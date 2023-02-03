#include <iostream>
#include <string>
#include "compare.hpp"

template <typename T>
int compare(const T&, const T&);

int main()
{
    std::cout << compare<std::string>("ab", "cpp") << '\n';
    return 0;
}