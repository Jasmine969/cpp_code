#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
struct draft
{
    long double i = 0;
};


int main()
{
    double i = 4;
    int j = 3;
    double slope = static_cast<double>(i/j);
    cout << slope << endl;
    return 0;
}