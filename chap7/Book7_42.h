#ifndef BOOK7_42_H
#define BOOK7_42_H

#include <string>
#include <iostream>

using std::cin;
using std::istream;
using std::ostream;
using std::string;

class Book;
ostream &print(ostream &, Book &);
class Book
{
    friend ostream &print(ostream &os, Book &book);

private:
    string name;
    string bookNo;
    string author;
    double price = 0;

public:
    Book(const string &book_name, const string &ISBN,
         const string &book_author, double book_price)
        : name(book_name), bookNo(ISBN), author(book_author), price(book_price) {}
    Book() : Book("", "", "", 0) {}
    Book(const string &ISBN) : Book(ISBN, "", "", 0) {}
    Book(istream &is) : Book()
    {
        is >> name >> bookNo >> author >> price;
    }
};

ostream &print(ostream &os, Book &book)
{
    os << book.name << '\t' << book.bookNo << '\t' << book.author << '\t' << book.price << '\n';
    return os;
}
#endif