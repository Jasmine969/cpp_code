#ifndef QUERY_EX30_H
#define QUERY_EX30_H

#include <memory>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>
#include "../myfunc.h"
#include <algorithm>

using std::getline;
using std::ifstream;
using std::istringstream;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

class QueryResult;

class TextQuery
{
    friend QueryResult;

private:
    shared_ptr<vector<string>> textPtr;
    map<string, shared_ptr<set<unsigned>>> wordPosMap;

public:
    TextQuery(ifstream &);
    QueryResult query(const string &) const;
};

TextQuery::TextQuery(ifstream &in) : textPtr(new vector<string>)
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
            remove_punct(word);
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
    friend ostream &print(ostream &, QueryResult, unsigned, unsigned);
    string savedWord;
    shared_ptr<vector<string>> textPtr;
    shared_ptr<set<unsigned>> linoPtr;

public:
    QueryResult(const string &word, shared_ptr<vector<string>> tp,
                shared_ptr<set<unsigned>> lp) : savedWord(word), textPtr(tp), linoPtr(lp){};
    set<unsigned>::iterator begin() const { return linoPtr->begin(); }
    set<unsigned>::iterator end() const { return linoPtr->end(); }
    shared_ptr<vector<string>> get_file() const { return textPtr; }
};

QueryResult TextQuery::query(const string &word) const
{
    static shared_ptr<set<unsigned>> nodata(new set<unsigned>);
    auto loc = wordPosMap.find(word);
    if (loc == wordPosMap.end())
    {
        return QueryResult(word, textPtr, nodata);
    }
    return QueryResult(word, textPtr, loc->second);
}

ostream &print(ostream &os, QueryResult qr, unsigned start = 1, unsigned end = 0)
{
    auto ret_lines = set<unsigned>();
    if (start == 1 && end == 0)
    {
        ret_lines = *qr.linoPtr;
    }
    else
    {
        end = (end == 0) ? qr.textPtr->size() : end;
        set<unsigned> allowed_lines;
        for (unsigned i = start; i != end + 1; ++i)
        {
            allowed_lines.insert(i);
        }
        ret_lines = set<unsigned>();
        std::set_intersection(allowed_lines.begin(), allowed_lines.end(),
                              qr.begin(), qr.end(),
                              std::inserter(ret_lines, ret_lines.begin()));
    }
    os << qr.savedWord << " occurs " << ret_lines.size() << (ret_lines.size() > 1 ? " times.\n" : " time.\n");
    for (unsigned n : ret_lines)
    {
        os << "\t(line " << n << ") " << (*qr.textPtr)[n - 1] << "\n";
    }
    return os;
}

#endif