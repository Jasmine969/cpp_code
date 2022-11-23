#include "StrBlobPtr_chap14.h"

class StrBlobPtrPtr
{
private:
    StrBlobPtr *sbpp;

public:
    StrBlobPtrPtr(StrBlobPtr sbp) : sbpp(&sbp) {}
    // StrBlobPtr &operator*() const;
    StrBlobPtr &operator->() const;
    // string *operator->() const;
};

StrBlobPtr &StrBlobPtrPtr::operator->() const
{
    return *sbpp; // 如果结果本身含有重载的 operator->()，则重复调用当前步骤
}

// StrBlobPtr *StrBlobPtrPtr::operator->() const
// {
    // return &**this;
// }

// string *StrBlobPtrPtr::operator->() const
// {
//     // return &**sbpp;
//     // return & sbpp->operator*();
//     // return sbpp->operator->();
//     return (*sbpp).operator->();
// }