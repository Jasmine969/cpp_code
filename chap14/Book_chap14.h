#ifndef BOOK_CHAP14_H
#define BOOK_CHAP14_H

#include <string>
#include <iostream>

using std::cin;
using std::getline;
using std::istream;
using std::ostream;
using std::string;

class Book;
ostream &print(ostream &, Book &);
class Book
{
    friend ostream &operator<<(ostream &os, const Book &book);
    friend istream &operator>>(istream &is, Book &book);
    friend bool operator==(const Book &, const Book &);

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
    Book(istream &is);
    Book &operator=(string &&);
    explicit operator bool() const;
};

ostream &operator<<(ostream &os, const Book &book)
{
    os << book.name << '\t' << book.bookNo << '\t'
       << book.author << '\t' << book.price;
    return os;
}

istream &operator>>(istream &is, Book &book)
{
    getline(is, book.name, '\n');
    getline(is, book.bookNo, '\n');
    getline(is, book.author, '\n');
    string str_price;
    getline(is, str_price, '\n');
    if (is)
    {
        try
        {
            book.price = std::stod(str_price);
        }
        catch (std::invalid_argument err)
        {
            book = Book();
        }
    }
    else
    {
        book = Book();
    }
    return is;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.name == rhs.name &&
           lhs.bookNo == rhs.bookNo &&
           lhs.author == rhs.author &&
           lhs.price == rhs.price;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

Book::Book(istream &is) : Book()
{
    getline(is, name, '\n');
    getline(is, bookNo, '\n');
    getline(is, author, '\n');
    string str_price;
    getline(is, str_price, '\n');
    price = std::stod(str_price);
}

Book &Book::operator=(string &&book_no)
{
    bookNo = book_no;
    return *this;
}

Book::operator bool() const
{
    return name.size() && bookNo.size() && author.size() && price;
}
#endif