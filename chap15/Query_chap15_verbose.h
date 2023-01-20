#ifndef QUERY_CHAP15_VERBOSE_H
#define QUERY_CHAP15_VERBOSE_H

#include "../chap12/Query_ex33.h"

using std::cout;

class Query;

class Query_base
{
    friend class Query;

protected:
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual string rep() const = 0;
};

// 在友元声明前声明三个非成员函数
Query operator~(const Query &);
Query operator&(const Query &, const Query &);
Query operator|(const Query &, const Query &);

class Query
{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);

public:
    Query(const string &);
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }
    string rep() const
    {
        return q->rep();
    }

private:
    Query(shared_ptr<Query_base> query) : q(query)
    {
        cout << "Query(shaerd_ptr<Query_base>)\n";
    }
    shared_ptr<Query_base> q;
};

ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery : public Query_base
{
    friend class Query;
    string query_word;
    WordQuery(const string &s) : query_word(s)
    {
        cout << "WordQuery(const string &)\n";
    }
    QueryResult eval(const TextQuery &t) const override
    {
        return t.query(query_word);
    }
    string rep() const override { return query_word; }
};

inline Query::Query(const string &s) : q(new WordQuery(s))
{
    cout << "Query(const string &)\n";
}

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    Query query;
    NotQuery(const Query &q) : query(q)
    {
        cout << "NotQuery(const Query &)\n";
    }
    QueryResult eval(const TextQuery &) const override {}
    string rep() const override
    {
        return "~(" + query.rep() + ")";
    }
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base
{
protected:
    Query lhs, rhs;
    string opSym;
    BinaryQuery(const Query &l, const Query &r, string s)
        : lhs(l), rhs(r), opSym(s)
    {
        cout << "BinaryQuery (const Query &, const Query &, const string &)\n";
    }
    string rep() const override
    {
        return "(" + lhs.rep() + " " + opSym + " " +  rhs.rep() + ")";
    }
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "&")
    {
        cout << "AndQuery(const Query &, const Query &)\n";
    }
    QueryResult eval(const TextQuery &) const override {}
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "|")
    {
        cout << "OrQuery(const Query &, const Query &)\n";
    }
    QueryResult eval(const TextQuery &t) const override {}
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif