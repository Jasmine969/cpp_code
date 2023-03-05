#ifndef DEBUG_REP_48_H
#define DEBUG_REP_48_H

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
  ostringstream oss;
  oss << t;
  return oss.str();
}

string debug_rep(const string &t)
{
#ifndef NDEBUG
  cout << "const string &\n";
#endif
  return '"' + t + '"';
}

string debug_rep(const char *t)
{
#ifndef NDEBUG
  cout << "const char *\n";
#endif
  return debug_rep(string(t));
}

string debug_rep(char *t)
{
#ifndef NDEBUG
  cout << "char *\n";
#endif
  return debug_rep(string(t));
}

#endif