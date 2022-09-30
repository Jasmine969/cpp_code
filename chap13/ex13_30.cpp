#include "HasPtr_ex30.h"

using std::swap;

int main()
{
    HasPtr hp1(0, "Abort");
    HasPtr hp2(1);
    swap(hp1, hp2);
    cout << hp1.get_str() << " " << hp2.get_str() << "\n";
    return 0;
}