#include <iostream>
#include <string>

using std::string;
using std::cout;

string* concatStr(const string& s1, const string& s2)
{
    auto s3 = new string[1] {s1 + s2};
    return s3;
} 

void fun()
{
    auto d = concatStr("I", "lOVE");
    cout << *d << '\n';
    delete [] d;
}

int main()
{
    fun();
    return 0;
}