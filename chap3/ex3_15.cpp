#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::vector;
using std::string;
int main()
{
    string tmp;
    vector<string> svec;
    while (cin >> tmp)
        svec.push_back(tmp);
    std::cout << svec.size() << std::endl;
    return 0;
}