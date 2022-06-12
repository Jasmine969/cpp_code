#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using std::string;
using std::vector;
using std::istream_iterator;
using std::ifstream;
using std::ostream_iterator;
using std::copy;
using std::cout;

int main()
{
    ifstream inp("../chap8/article.txt");
    istream_iterator<string> in_iter(inp), eof;
    vector<string> vstr(in_iter, eof);
    // vector<string> vstr; copy(in_iter, eof, std::back_inserter(vstr));
    copy(vstr.cbegin(), vstr.cend(), ostream_iterator<string>(cout, " "));
    return 0;
}