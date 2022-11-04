#include "StrBlobPtr_ex55.h"
#include <string>

using std::string;

int main()
{
    StrBlob sb;
    sb.push_back("abc");
    string s("jesus");
    sb.push_back(s);
    return 0;
}