#include <string>

using std::string;

class HasPtr
{
private:
    string *ps;
    int i;
    size_t *use;

public:
    HasPtr(const string &s = "") : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr();
    const string& get_str() const { return *ps; }
    void set_str(const string& s) { *ps = s; }
};

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // 如果自赋值，则不会进if
    if (--*use == 0)
    {
        delete use;
        delete ps;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        delete use;
        delete ps;
    }
}