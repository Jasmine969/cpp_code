#include "Book_chap14.h"
#include <iostream>

using std::cout;

int main()
{
    Book book("C F D", "a-1111","Versteeg", 60.56);
    Book book1(cin);
    cout << std::boolalpha << (book == book1) << '\n';
    cout << (book != book1) << '\n';
    return 0;
}