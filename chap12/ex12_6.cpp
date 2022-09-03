#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::back_inserter;
using std::cin;
using std::copy;
using std::cout;
using std::istream_iterator;
using std::nothrow;
using std::ostream_iterator;
using std::vector;

vector<int> *genVec()
{
    return new (nothrow) vector<int>;
}

void updateVec(vector<int> *v)
{
    istream_iterator<int> in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(*v));
}

void printVec(vector<int> *v)
{
    ostream_iterator<int> out_iter(cout, " ");
    copy(v->begin(), v->end(), out_iter);
}

int main()
{
    auto vp = genVec();
    updateVec(vp);
    printVec(vp);
    delete vp;    // 在main函数比在printVec释放内存更合适
    vp = nullptr; // 指出指针不指向任何对象
    return 0;
}