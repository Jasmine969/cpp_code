#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

struct Person
{
    string name;
    string address;
    const string& get_name() const {return name;}
    const string& get_addr() const {return address;}
};

istream& read(istream& is, Person& ps)
{
    is >> ps.name >> ps.address;
    return is;
}

ostream& print(ostream& os, const Person& ps)
{
    os << ps.get_name() << '\t' << ps.get_addr();
    return os;
}
