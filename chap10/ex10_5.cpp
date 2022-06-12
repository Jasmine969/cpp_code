#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>
#include "../myfunc.h"

using std::vector;
using std::equal;
using std::list;
using std::string;
using std::cout;

int main()
{
    cout << std::boolalpha;
    vector<const char*> vs1{"If", "I", "got"};
    list<const char*> vs2{"If", "I", "got", "locked"};
    vector<const char*> vs3{strdup(vs1[0]), strdup(vs1[1]), strdup(vs1[2])};
    cout << equal(vs1.cbegin(), vs1.cend(), vs2.cbegin()) << '\n';
    printVec(vs3);    
    return 0;
}