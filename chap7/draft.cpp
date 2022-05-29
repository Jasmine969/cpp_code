#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include "draft.h"

// TODO:待完成
// BUG:这里有个bug
// NOTE:
// FIXME:待修改
// XXX:这里实现得很草率要进一步修改
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Account
{
public:
    static double rate() { return interestRate; }
    // static void rate(double newRate) {interestRate = newRate;}
// private:
    string owner;
    double amount;
    const static double interestRate;
    static double initRate;
};

constexpr double Account::interestRate = 0.2;

int main()
{
    cout << Account::interestRate << endl;
    return 0;
}