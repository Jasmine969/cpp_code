
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class C
{
	public:
	int a;
	C(int aa=0) : a(aa) {};
	~C(){
		cout << "delete C" << endl;
	};
};
void foo()
{
	unique_ptr<C> up(new C(10));
	shared_ptr<int> sp1(new int (11)); //产生异常
	weak_ptr<int> wp(sp1);
}
int main()
{	
	foo();
	return 0;
}