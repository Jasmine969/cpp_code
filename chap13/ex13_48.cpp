#include "String_ex47.h"
#include <vector>

int main()
{
	std::vector<String> v;
	String ss;
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back("aaa");
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back("bbb");
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back(ss);
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back(ss);
	cout << v.size() << "\t" << v.capacity() << '\n';
	v.push_back(ss);
	cout << v.size() << "\t" << v.capacity() << '\n';
	return 0;
}