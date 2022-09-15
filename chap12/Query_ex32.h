/*
* 因为StrBlob本身就是用shared_ptr管理对象的，
* 所以换掉的应该是shared_ptr<vector<string>>，
* 而不仅仅是vector<string>。
* 完全没有必要定义一个指向StrBlob的share_ptr了。
* 另外，StrBlob应该添加一个构造函数，
* 可以用指向vector<string>的指针来初始化StrBlob。
*/
#ifndef QUERY_EX30_H
#define QUERY_EX30_H

#include <memory>
#include "StrBlobPtr_ex19.h"
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>

using std::getline;
using std::ifstream;
using std::istringstream;
using std::make_pair;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;

class QueryResult;

class TextQuery
{
    friend QueryResult;

private:
    StrBlob textPtr;
    map<string, shared_ptr<set<unsigned>>> wordPosMap;

public:
    TextQuery(ifstream &);
    QueryResult query(const string &);
};

// 另外，StrBlob应该添加一个构造函数，可以用指向vector<string>的指针来初始化StrBlob。
TextQuery::TextQuery(ifstream &in): textPtr(new vector<string>)
{
    string line;
    unsigned lino = 0;
    while (getline(in, line))
    {
        ++lino;
        textPtr.push_back(line);
        istringstream line_stream(line);
        string word;
        while (line_stream >> word)
        {
            auto &linos = wordPosMap[word];
            if (!linos)
            {
                linos.reset(new set<unsigned>);
            }
            linos->insert(lino);
        }
    }
}

struct QueryResult
{
    string savedWord;
    StrBlob textPtr;
    shared_ptr<set<unsigned>> linoPtr;
    QueryResult(const string &word, StrBlob tp,
                shared_ptr<set<unsigned>> lp) : savedWord(word), textPtr(tp), linoPtr(lp){};
};

QueryResult TextQuery::query(const string &word)
{
    static shared_ptr<set<unsigned>> nodata(new set<unsigned>);
    auto loc = wordPosMap.find(word);
    if (loc == wordPosMap.end())
    {
        return QueryResult(word, textPtr, nodata);
    }
    return QueryResult(word, textPtr, wordPosMap[word]);
}

ostream &print(ostream &os, QueryResult qr)
{
    os << qr.savedWord << " occurs " << qr.linoPtr->size()
       << (qr.linoPtr->size() > 1 ? " times.\n" : " time.\n");
    for (unsigned n : *qr.linoPtr)
    {
        os << "\t(line " << n << ") ";
        auto q = qr.textPtr.begin();
        for (; n != 1; --n, q.incr());
        os << q.deref() << "\n";
    }
    return os;
}

#endif