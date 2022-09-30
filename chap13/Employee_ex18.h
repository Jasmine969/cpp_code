#ifndef EMPLOYEE_EX18_H
#define EMPLOYEE_EX18_H

#include <string>
#include <sstream>
#include <iomanip>

using std::ostringstream;
using std::setfill;
using std::setw;
using std::string;

class Employee
{
    static unsigned allcoated;
    string name;
    string id;
    static string format(unsigned);

public:
    Employee() : id(format(allcoated++)) {}
    Employee(const string &name_) : name(name_), id(format(allcoated++)) {}
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    string getName() const {return name;}
    string getId() const {return id;}
};

unsigned Employee::allcoated = 0;
string Employee::format(unsigned i)
{
    ostringstream oss;
    oss << setfill('0') << setw(10);
    oss << i;
    string s = oss.str();
    return s;
}

#endif