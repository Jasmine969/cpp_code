#include <memory>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>

using std::cout;
using std::make_shared;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;
using std::weak_ptr;

class Foo
{
public:
    int* p = new int;
    map<string, shared_ptr<set<unsigned>>> pt;
    void fun()
    {
        pt["word"].reset(new set<unsigned>);
    }
};

class Prot_Foo : protected Foo
{

};

int main()
{
    shared_ptr<set<char>> ps;
    ps->insert('s');
    return 0;
}