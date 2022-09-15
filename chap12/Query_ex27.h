#ifndef QUERY_EX27_H
#define QUERY_EX27_H

#include <memory>
#include <vector>
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
using std::vector;

class QueryResult;

class TextQuery
{
    friend QueryResult;

private:
    shared_ptr<vector<string>> textPtr{make_shared<vector<string>>()};
    map<string, shared_ptr<set<unsigned>>> wordPosMap;
    map<string, unsigned> wordCount;

public:
    TextQuery(ifstream &);
    QueryResult query(const string &);
};

TextQuery::TextQuery(ifstream &in)
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
            if (wordPosMap.find(word) == wordPosMap.end())
            {
                set<unsigned> s; // 一定要提前给set分配内存，不然没法insert
                // 如果word已经在wordPosMap里面，emplace就是无效的，见P384-385。所以emplace可以不在if语句里面
                wordPosMap.emplace(word, make_shared<set<unsigned>>(s));
            }
            wordPosMap[word]->insert(lino);
            ++wordCount[word];
        }
    }
}

struct QueryResult
{
    string savedWord;
    TextQuery tq;
    shared_ptr<vector<string>> textPtr;
    unsigned cnt;
    shared_ptr<set<unsigned>> linoPtr;
    QueryResult(TextQuery &, const string &word);
};

QueryResult::QueryResult(TextQuery &tq, const string &word) : tq(tq), textPtr(tq.textPtr)
{
    savedWord = word; // TODO const 为什么能给非const？
    /* const引用能给非const，但不能给非const引用。
     因为改变非const是不会变const引用的，但是改变非const引用则会改变const引用。 */
    if (tq.wordCount.find(word) == tq.wordCount.end())
    {
        cnt = 0;
        linoPtr = make_shared<set<unsigned>>();
    }
    else
    {
        cnt = tq.wordCount[word];
        linoPtr = tq.wordPosMap[word];
    }
}

QueryResult TextQuery::query(const string &word)
{
    QueryResult qr(*this, word);
    return qr;
}

ostream &print(ostream &os, QueryResult qr)
{
    os << qr.savedWord << " occurs " << qr.cnt << (qr.cnt > 1 ? " times.\n" : " time.\n");
    for (unsigned n : *qr.linoPtr)
    {
        os << "\t(line " << n << ") " << (*qr.textPtr)[n - 1] << "\n";
    }
    return os;
}

#endif