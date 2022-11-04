#include "StrVec_chap14.h"

int main()
{
    StrVec sv1{"I", "Love"};
    StrVec sv2{"I", "Love"};
    StrVec sv3{"I", "LOve"};
    cout << std::boolalpha << (sv1 == sv2) << '\t' << (sv1 == sv3) << '\n';
    cout << std::boolalpha << (sv1 != sv2) << '\t' << (sv1 != sv3) << '\n';
    return 0;
}