#include "Query_chap15_verbose.h"

int main()
{
    Query q = ~Query("fiery") & Query("bird") | Query("wind");
    cout << q.rep() << '\n';
    return 0;
}