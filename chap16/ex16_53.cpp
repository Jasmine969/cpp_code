#include <iostream>
#include <string>
#include "print_ex53.h"

int main()
{
    print(std::cout, 'c', "genius", 1.3, std::string(4, 'e'));
    print(std::cout, 'c', "genius");
    print(std::cout, 'c');
    return 0;
}