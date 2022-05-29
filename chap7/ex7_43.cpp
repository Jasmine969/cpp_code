struct NoDefault
{
    int val;
    NoDefault(int i): val(i) {}
};

class C
{
    public:
    NoDefault my_mem;
    C(): my_mem(0) {}
};
