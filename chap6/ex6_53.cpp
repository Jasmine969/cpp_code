#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void calc(int &, int &) { cout << "f1 called" << endl; }
void calc(const int &, const int &) { cout << "f2 called" << endl; }
void salc(char *cc1, char *cc2)
{
    cout << cc1 << ' ' << cc2 << endl;
    cout << "f3 called" << endl;
}
void salc(const char *cc1, const char *cc2)
{
    cout << cc1 << ' ' << cc2 << endl;
    cout << "f4 called" << endl;
}

int main()
{
    int i = 1, j = 2;
    const int ci = 1, cj = 2;
    int &ri = i, &rj = j;
    const int &rci = 1, &rcj = 2;
    calc(1, 1);     // f2
    calc(i, j);     // f1
    calc(ri, rj);   // f1
    calc(rci, rcj); // f2
    calc(1, j);     // f2
    cout << string(10, '=') << endl;
    string s1 = "hello", s2 = "world";
    // char *c1 = "hello", *c2 = "world";
    char d1 = 'p', d2 = 'q';
    char *c3 = &d1, *c4 = &d2;
    // salc(c1, c2);           // f3
    salc(c3, c4);           // f4
    salc("hello", "world"); // f4
    // salc("hello", c2); // ambiguous call
    return 0;
}