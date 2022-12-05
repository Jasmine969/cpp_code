#include <iostream>

using std::cout;

struct SmallInt
{
    SmallInt(int i = 0) : val(i) { cout << "Constructor of SmallInt" << '\n'; }
    operator int() const
    {
        cout << "operator int of SmallInt\n";
        return val;
    }
    std::size_t val;
};

SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
{
    cout << "SmallInt + SmallInt\n";
    return lhs.val + rhs.val;
}

struct LongDouble
{
    LongDouble operator+(const SmallInt &rhs)
    {
        LongDouble lhs(*this);
        lhs.val += rhs.val;
        cout << "operator+ of LongDouble\n";
        return lhs;
    }
    long double val;
    LongDouble(double i = 0.0) : val(i)
    {
        cout << "Constructor of LongDouble" << '\n';
    }
    operator double()
    {
        cout << "double of LongDouble" << '\n';
        return val;
    }
    operator float() { return val; }
};

LongDouble operator+(LongDouble &lhs, double rhs)
{
    cout << "operator+ of LongDouble" << '\n';
    return lhs.val + rhs;
}

int main()
{
    SmallInt si(1);
    LongDouble ld(2);
    cout << "==========\n";
    // LongDouble(si) + ld;
    return 0;
}