#ifndef DEBUG_REP_H
#define DEBUG_REP_H

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

template <typename T>
string debug_rep(const T &t)
{
#ifndef NDEBUG
  cout << "const T &\n";
#endif
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
string debug_rep(T *p)
{
#ifndef NDEBUG
  cout << "T *p\n";
#endif
  ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}

template <>
string debug_rep(const char *p)
{
#ifndef NDEBUG
  cout << "const char *p\n";
#endif
  ostringstream ret;
  ret << p;
  return ret.str();
}

template <>
string debug_rep(char *p)
{
#ifndef NDEBUG
  cout << "char *p\n";
#endif
  ostringstream ret;
  ret << p;
  return ret.str();
}
#endif