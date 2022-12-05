#include "Book_chap14.h"
#include <iostream>

using std::cout;

int main()
{
    Book book{
        // "C++ Primer",
        "978-7-121-15535-2",
        // "Lippman",
        // 128
    };
    cout << (book ? "yes" : "no") << '\n';
    return 0;
}