#ifndef QUERY_CHAP15_H
#define QUERY_CHAP15_H

#include "../chap12/Query_ex33.h"
#include <algorithm>
#include <iterator>

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
    Query(shared_ptr<Query_base> query) : q(query) {}
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
    WordQuery(const string &s) : query_word(s) {}
    QueryResult eval(const TextQuery &t) const override
    {
        return t.query(query_word);
    }
    string rep() const override { return query_word; }
};

inline Query::Query(const string &s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    Query query;
    NotQuery(const Query &q) : query(q) {}
    QueryResult eval(const TextQuery &) const override;
    string rep() const override
    {
        return "~(" + query.rep() + ")";
    }
};

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto ori_lines = query.eval(text);
    auto file = ori_lines.get_file();
    set<unsigned> all_lines;
    for (unsigned i = 0; i != file->size(); ++i)
    {
        all_lines.insert(i + 1);
    }
    auto ret_lines = make_shared<set<unsigned>>();
    std::set_difference(all_lines.begin(), all_lines.end(),
                        ori_lines.begin(), ori_lines.end(),
                        std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), file, ret_lines);
    // 这是书上的代码
    // auto result = query.eval(text);
    // auto ret_lines = make_shared<set<unsigned>>();
    // auto beg = result.begin(), end = result.end();
    // auto sz = result.get_file()->size();
    // for (size_t n = 1; n != sz + 1; ++n)
    // {
    //     if (beg == end || *beg != n)
    //         ret_lines->insert(n);
    //     else if (beg != end)
    //         ++beg;
    // }
    // return QueryResult(rep(), result.get_file(), ret_lines);
}

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base
{
protected:
    Query lhs, rhs;
    string opSym;
    BinaryQuery(const Query &l, const Query &r, const string &s)
        : lhs(l), rhs(r), opSym(s) {}
    string rep() const override
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right)
        : BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery &) const override;
};

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<unsigned>>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), left.get_file(), ret_lines);
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &l, const Query &r)
        : BinaryQuery(l, r, "|") {}
    QueryResult eval(const TextQuery &) const override;
};

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<unsigned>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), left.get_file(), ret_lines);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif