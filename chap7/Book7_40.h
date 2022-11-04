#ifndef BOOK7_40_H
#define BOOK7_40_H

#include <string>
#include <iostream>

using std::cin;
using std::istream;
using std::string;

class Book
{
private:
    string name;
    string bookNo;
    string author;
    double price = 0;

public:
    Book(const string &ISBN) : bookNo(ISBN) {}
    Book(const string &book_name, const string &ISBN,
         const string &book_author, double book_price)
        : name(book_name), bookNo(ISBN), author(book_author), price(book_price) {}
    Book(istream &is = cin)
    {
        is >> name >> bookNo >> author >> price;
    }
};

#endif