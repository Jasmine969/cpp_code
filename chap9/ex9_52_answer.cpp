#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::getline;
using std::invalid_argument;
using std::stack;
using std::stod;
using std::string;

enum obj_type
{
    LP,
    RP,
    ADD,
    SUB,
    VAL
};
struct obj
{
    obj(obj_type type, double val = 0) : t(type), v(val) {}
    obj_type t;
    double v;
};
inline void skipws(const string &exp, string::size_type &p)
{
    p = exp.find_first_not_of(" ", p);
}

void newVal(stack<obj> &so, double v)
{
    if (so.empty() || so.top().t == LP)
    {
        so.emplace(VAL, v);
    }
    else if (so.top().t == ADD || so.top().t == SUB)
    {
        obj_type type_curr = so.top().t;
        so.pop();
        if (type_curr == ADD)
        {
            v += so.top().v;
        }
        else
        {
            v = so.top().v - v;
        }
        so.pop();
        so.emplace(VAL, v);
    }
    else
    {
        throw invalid_argument("no operator");
    }
}

int main()
{
    stack<obj> so;
    string exp;
    string::size_type p = 0, q;
    double v;
    getline(cin, exp);
    while (p != exp.size())
    {
        skipws(exp, p);
        if (exp[p] == '(')
        {
            // 这边不用给obj的val赋值，因为是左括号，赋值无意义
            so.emplace(LP);
            ++p;
        }
        else if (exp[p] == '+' || exp[p] == '-')
        {
            if (so.empty() || so.top().t != VAL)
            {
                throw invalid_argument("no operand");
            }
            if (exp[p] == '+')
            {
                so.emplace(ADD);
            }
            else
            {
                so.emplace(SUB);
            }
            ++p;
        }
        else if (exp[p] == ')')
        {
            if (so.empty())
            {
                throw invalid_argument("no match of RP");
            }
            if (so.top().t == LP)
            {
                throw invalid_argument("empty parenthesis");
            }
            if (so.top().t != VAL)
            {
                throw invalid_argument("no operand");
            }
            v = so.top().v;
            so.pop(); // pop up the val
            if (so.top().t != LP || so.empty())
            {
                throw invalid_argument("no match of RP");
            }
            so.pop(); // pop up LP
            newVal(so, v);
            ++p;
        }
        else // the current char denotes a double value
        {
            // 这个地方要考虑v为123的情况，那么三个数都要读进去
            // 所以用substr(p) 把后面所有东西都读进去，然后用stod转换连续的数字
            // 把最后一个转换的之后的非数字字符的下标给q
            // 然后用p+=q来跳过123，比如这边q肯定是3，那么就跳三个字符到非数字字符
            v = stod(exp.substr(p), &q);
            newVal(so, v);
            p += q;
        }
    }
    if (so.size() != 1 || so.top().t != VAL)
    {
        throw invalid_argument("invalid expression");
    }
    cout << exp << " = " << so.top().v << "\n";
    return 0;
}