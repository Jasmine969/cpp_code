#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template <typename T, typename D = void (*)(T *)>
class uniquePtr
{
private:
    T *p;
    D del;
    static void defaultDelete(T *ptr) { delete ptr; }

public:
    uniquePtr() : p(nullptr), del(defaultDelete) {}
    explicit uniquePtr(T *ptr) : p(ptr), del(defaultDelete) {}
    explicit uniquePtr(T *ptr, D deleter) : p(ptr), del(deleter) {}
    uniquePtr(const uniquePtr &) = delete;
    uniquePtr(uniquePtr &&) noexcept;
    uniquePtr &operator=(const uniquePtr &) = delete;
    uniquePtr &operator=(uniquePtr &&) noexcept;
    ~uniquePtr();

    T *release();
    void reset(T *q = nullptr);
    T &operator*() { return *p; }
    T &operator*() const { return *p; }
    T *operator->() { return &**this; }
    T *operator->() const { return &**this; }
};

template <typename T, typename D>
uniquePtr<T, D>::uniquePtr(uniquePtr &&up) noexcept
    : p(up.p), del(up.del)
{
    up.p = nullptr;
}

template <typename T, typename D>
uniquePtr<T, D> &uniquePtr<T, D>::operator=(uniquePtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        this->~uniquePtr();
        p = rhs.p;
        del = rhs.del;
        rhs.p = nullptr;
    }
    return *this;
}

template <typename T, typename D>
uniquePtr<T, D>::~uniquePtr()
{
    del(p);
}

template <typename T, typename D>
T *uniquePtr<T, D>::release()
{
    T *tmp = p;
    p = nullptr;
    return tmp;
}

template <typename T, typename D>
void uniquePtr<T, D>::reset(T *q)
{
    this->~uniquePtr();
    p = q;
}

#endif