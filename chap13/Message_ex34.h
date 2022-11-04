#ifndef MESSAGE_EX34_H
#define MESSAGE_EX34_H

#include <string>
#include <set>

using std::set;
using std::string;

class Folder;
class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

private:
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
    void addFldr(Folder* fp) {folders.insert(fp);}
    void remFldr(Folder* fp) {folders.erase(fp);}

public:
    void save(Folder &);                                    // 向给定Folder添加Message
    void remove(Folder &);                                  // 向给定Folder删除Message
    explicit Message(const string &s = "") : contents(s) {} // constructor
    Message(const Message &);                               // copy constructor
    Message &operator=(const Message &);                    // copy assignment operator
    ~Message();                                             // destructor
};

class Folder
{
    friend class Message;
    friend void swap(Message &, Message &);
    void addMsg(Message *);
    void remMsg(Message *);
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

private:
    set<Message *> messages;
    void add_to_Messages(const Folder &f);
    void remove_from_Messages();
};

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
}

Message::~Message()
{
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Folder::addMsg(Message *mp)
{
    messages.insert(mp);
}

void Folder::remMsg(Message *mp)
{
    messages.erase(mp);
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.messages)
    {
        m->addFldr(this);
    }
}

void Folder::remove_from_Messages()
{
    for (auto m : messages)
    {
        m->remFldr(this);
    }
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
    add_to_Messages(f);
}

Folder::~Folder()
{
    remove_from_Messages();
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Messages();
    messages = rhs.messages;
    add_to_Messages(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    for (auto f : lhs.folders)
    {
        f->remMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->remMsg(&rhs);
    }
    using std::swap; // a good habit though not required
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f : lhs.folders)
    {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.folders)
    {
        f->addMsg(&rhs);
    }
}

#endif