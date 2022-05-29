#include <vector>
#include "Chapter6.h"

using std::vector;
inline int add(int x, int y) { return x + y; }
inline int minus(int x, int y) { return x - y; }
inline int times(int x, int y) { return x * y; }
inline int divide(int x, int y) { return x / y; }
// vector<decltype(add) *> fvec = {add, minus, times, divide};
vector<int (*)(int, int)> fvec = {add, minus, times, divide};