#include <vector>
using std::vector;

class NoDefault
{
    int val;
    NoDefault(int i) : val(i) {}
};

template class std::vector<NoDefault>;
int main()
{
    return 0;
}