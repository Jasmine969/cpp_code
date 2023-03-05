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
#include <initializer_list>
#include "../test.h"

using std::cout;
using std::string;
using namespace std::placeholders;
using std::back_inserter;
using std::ostream;
using std::vector;

template <typename T>
void f(const T &) { cout << "const T&\n"; };

void f(const long &) { cout << "const long &\n"; }

int main()
{
  f(1);
  return 0;
}