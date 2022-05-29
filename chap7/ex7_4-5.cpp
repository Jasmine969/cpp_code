#include <iostream>
#include <string>

using std::string;

struct Person
{
    string name;
    string address;
    const string& get_name() const {return name;}
    const string& get_addr() const {return address;}
};