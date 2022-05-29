#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Person
{
    friend istream& read(istream&, Person&);
private:
    string name;
    string address;

public:
    const string &get_name() const { return name; }
    const string &get_addr() const { return address; }
    Person() = default;
    explicit Person(const string &s_name) : name(s_name){};
    Person(const string &s_name, const string &s_addr) : name(s_name), address(s_addr){};
    explicit Person(istream &is);
};

istream &read(istream &is, Person &ps)
{
    is >> ps.name >> ps.address;
    return is;
}

ostream &print(ostream &os, const Person &ps)
{
    os << ps.get_name() << '\t' << ps.get_addr();
    return os;
}

Person::Person(istream &is)
{
    read(is, *this);
}