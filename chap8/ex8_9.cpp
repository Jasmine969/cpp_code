#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using std::istream;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::istringstream;
using std::cerr;
using std::runtime_error;


istringstream& print(istringstream& is)
{
    string s;
    while (is >> s, !is.eof())
    {
        if (is.bad())
        {
            throw runtime_error("System error!");
        }
        if (is.fail())
        {
            cerr << "Data error! Enter again:" << endl;
            is.clear();
            is.ignore(100, '\n'); // 忽略掉那些字符串
            continue;
        }
        cout << s << endl;
    }
    is.clear();
    return is;
}

int main()
{
    string s1;
    while (getline(cin, s1))
    {
        istringstream iss(s1);
        auto &res = print(iss);
        cout << res.good() << endl;
    }
    return 0;
}