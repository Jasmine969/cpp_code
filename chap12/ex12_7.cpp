#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>

using std::back_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::cout;
using std::cin;
using std::vector;
using std::copy;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> genVec()
{
    return make_shared<vector<int>>();
}

void updateVec(shared_ptr<vector<int>> v)
{
    istream_iterator<int> in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(*v));
}

void printVec(shared_ptr<vector<int>> v)
{
    ostream_iterator<int> out_iter(cout, " ");
    copy(v->begin(), v->end(), out_iter);
}

int main()
{
    auto vp = genVec();
    updateVec(vp);
    printVec(vp);
    return 0;
}