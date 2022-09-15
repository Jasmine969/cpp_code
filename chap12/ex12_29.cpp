#include <iostream>
#include <string>
#include <fstream>
#include "Query_ex27.h"

using std::cout;
using std::cin;
using std::ifstream;
using std::string;

class TextQuery;
class QueryResult;
std::ostream& print(std::ostream&, QueryResult);

void runQueries (ifstream& infile)
{
    TextQuery tq(infile);
    string s;
    cout << "enter word to look for\n";
    cin >> s; // 默认第一次不退出
    do
    {
        print(cout, tq.query(s)) << '\n';
        cout << "enter word to look for, or q to quit\n";
    } while ((cin >> s) && s != "q");
}

int main()
{
    ifstream in("lyrics2.txt");
    runQueries(in);
    return 0;
}