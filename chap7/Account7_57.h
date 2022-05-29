#include <string>

using std::string;

class Account
{
public:
    Account(const string& ow, double money): owner(ow), amount(money) {}
    Account& calculate() {amount += amount * interestRate; return *this;}
    double rate() {return interestRate;}
    Account& rate(double newRate) {interestRate = newRate; return *this;}
    double get_amount() {return amount;}
private:
    string owner;
    double amount;
    static double interestRate;
    constexpr static double initRate = 0.01;
};

double Account::interestRate = initRate;