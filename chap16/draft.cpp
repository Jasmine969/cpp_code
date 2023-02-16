#include <iostream>
#include <string>
#include <algorithm>
#include "Blob.h"
#include <functional>
#include <vector>
#include <iterator>
#include "../myfunc.h"
#include <memory>
#include <typeinfo>

using std::cout;
using std::string;
using namespace std::placeholders;
using std::back_inserter;
using std::ostream;
using std::vector;

template <typename T>
void f(const T &t)
{
  cout << "const T &\n";
  cout << t << '\n';
}

// void f(const string &t);

void f(const char *t)
{
  cout << "const char *\n";
  f(string(t));
}
// void f(char *t)
// {
//   cout << "char *\n";
//   f(string(t));
// }
// void f(const char (&t)[5])
// {
//   cout << "char [5]\n";
//   cout << t << '\n';
// }

static int a = 10;

int main()
{
  f("helo");
  return 0;
}