#include <iostream>
#include <string>

using std::cout;
using std::string;

template <typename T>
void debug_rep(const T &t)
{
  cout << "const T &\n";
  cout << t << '\n';
}

void debug_rep(const string &t)
{
  cout << "const string &\n";
  cout << t << '\n';
}

void debug_rep(const char *t)
{
  cout << "const char *\n";
  debug_rep(string(t));
}

void debug_rep(char *t)
{
  cout << "char *\n";
  debug_rep(string(t));
}

static int a = 10;

int main()
{
  debug_rep("helo");
  return 0;
}