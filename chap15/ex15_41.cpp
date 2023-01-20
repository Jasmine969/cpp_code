#include "Query_ex41.h"
#include <iostream>

using std::cout;

int main()
{
    ifstream in("Alice.txt");
    TextQuery text(in);
    // Query q = ~(Query("fiery") & Query("bird")) | Query("wind");
    Query q = ~Query("fiery");
    auto ret = q.eval(text);
    print(cout, ret);
    return 0;
}