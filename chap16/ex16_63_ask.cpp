template <typename T>
void f(const T &v2) {}

template <typename T>
void g(T v1) {}

template <typename T>
void h(T v1, const T &v2) {}

int main()
{
    h<const char*>("hello", "hello");
    return 0;
}