#include "Account7_57.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Account ac("zhuh", 200);
    cout << ac.rate() << endl;
    cout << ac.rate(0.3).calculate().get_amount() << endl;
    cout << ac.rate(1).calculate().get_amount() << endl;
    return 0;
}