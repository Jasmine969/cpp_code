#include <iostream>
#include "Sales_data_ex41.h"

using std::endl;
using std::cout;

int main()
{
    cout << "call 1" << endl;
    Sales_data sale1("abc", 12, 20.4);
    print(cout, sale1) << '\n';
    cout << string(10, '=') << '\n';

    cout << "call 2" << '\n';
    Sales_data sale2;
    print(cout, sale2) << '\n';
    cout << string(10, '=') << '\n';
    
    cout << "call 3" << '\n';
    Sales_data sale3("abc3");
    print(cout, sale3) << '\n';
    cout << string(10, '=') << '\n';

    cout << "call 4" << '\n';
    Sales_data sale4(cin);
    print(cout, sale4) << '\n';
    cout << string(10, '=') << '\n';
    return 0;
}