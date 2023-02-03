#include <iostream>
#include <string>
#include <fstream>
#include "Query_ex22.h"

using std::cout;
using std::cin;
using std::ifstream;
using std::string;

void runQueries (ifstream& infile)
{
    TextQuery tq(infile);
    string s;
    while (true)
    {
        cout << "enter word to look for, or q to quit\n";
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << '\n';
    }
}

int main()
{
    ifstream in("../chap12/lyrics2.txt");
    runQueries(in);
    return 0;
}
