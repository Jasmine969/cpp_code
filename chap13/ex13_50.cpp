#include "String_ex49.h"
#include <vector>
#include <string>

using std::string;

const char* f() { return "abcd"; }
int main()
{
	std::vector<String> v;
	String ss;
	cout << v.size() << "\t" << v.capacity() << '\n'; // 0 0
	v.push_back("aaa");
	cout << v.size() << "\t" << v.capacity() << '\n'; // 1 1
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n'; // 2 2
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n'; // 3 4
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n'; // 4 4
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n'; // 5 8
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n'; //6 8
	v.push_back(ss);
	cout << v.size() << "\t" << v.capacity() << '\n'; // 7 8
	v.push_back(f());
	cout << v.size() << "\t" << v.capacity() << '\n'; // 8 8
	v.push_back(std::move(ss));
	cout << v.size() << "\t" << v.capacity() << '\n'; // 9 16
	return 0;
}