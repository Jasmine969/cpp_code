#include <iostream>
#include <string>
#include <stdexcept>

using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::cerr;
using std::runtime_error;


istream& print(istream& is)
{
    int v;
    while (is >> v, !is.eof())
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
        cout << v << endl;
    }
    is.clear();
    return is;
}

int main()
{
    auto &res = print(cin);
    cout << res.good() << endl;
    return 0;
}