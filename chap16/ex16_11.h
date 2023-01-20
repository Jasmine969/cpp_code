#ifndef EX16_11_H
#define EX16_11_H

template <typename elemType> class ListItem;
template <typename elemType> class List
{
public:
    List();
    List(const List &);
    List& operator=(const List &);
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};

#endif