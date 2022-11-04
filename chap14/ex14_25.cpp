#include "Book_chap14.h"
#include <iostream>

using std::cout;

int main()
{
    Book book("CFD", "A-1-1","MALALASEKERA", 199);
    cout << book << '\n';
    book = "A-1-2";
    cout << book << '\n';
    return 0;
}