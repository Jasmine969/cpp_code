#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>
#include <utility>
#include <vector>

using std::copy;
using std::cout;
using std::find;
using std::list;
using std::make_pair;
using std::map;
using std::multimap;
using std::ostream_iterator;
using std::pair;
using std::set;
using std::string;
using std::swap;
using std::vector;

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, size_t> unmap;	// 默认构造一个无序容器
    string word;		// 要插入的数
    while(cin >> word && cin.get() != '\n')
         ++unmap[word];
         
    for(const auto& w:unmap)
    {
        cout << w.first << " occurs " << w.second << 
       		 ((w.second > 1)? " times   " : " time   ") <<
             unmap.bucket(w.first) << endl;
    }

    cout << unmap.bucket_count() << endl;		// 目前桶的数目
    cout << unmap.max_bucket_count() << endl;		// 桶的最大数目
    cout << unmap.bucket("hua") << endl;	// 该键对应的值有几个
    return 0;
}