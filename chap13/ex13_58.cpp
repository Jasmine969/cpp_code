#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;
using std::sort;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
    vector<int> data{4,2,3};
    Foo operator+(const Foo& rhs)
    {
        for (unsigned i = 0; i != data.size(); ++i)
        {
            data[i] += rhs.data[i];
        }
        return *this;
    }
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    cout << "call &&\n";
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "call const &\n";
    Foo ret(*this);
    return ret.sorted();
    // return Foo(*this).sorted();
}

int main()
{
    Foo v1;
    v1.sorted();
    return 0;
}