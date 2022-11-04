#ifndef QUERY_EX42_H
#define QUERY_EX42_H

#include <memory>
#include "StrVec_ex43.h"
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
    shared_ptr<StrVec> textPtr;
    map<string, shared_ptr<set<unsigned>>> wordPosMap;

public:
    TextQuery(ifstream &);
    QueryResult query(const string &);
};

TextQuery::TextQuery(ifstream &in) : textPtr(new StrVec)
{
    string line;
    unsigned lino = 0;
    while (getline(in, line))
    {
        ++lino;
        textPtr->push_back(line);
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
    shared_ptr<StrVec> textPtr;
    shared_ptr<set<unsigned>> linoPtr;
    QueryResult(const string &word, shared_ptr<StrVec> tp,
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
    os << qr.savedWord << " occurs " << qr.linoPtr->size() << (qr.linoPtr->size() > 1 ? " times.\n" : " time.\n");
    for (unsigned n : *qr.linoPtr)
    {
        os << "\t(line " << n << ") " << (*qr.textPtr)[n - 1] << "\n";
    }
    return os;
}

#endif