// 1. Multimap is an associative container that contains a sorted list of key-value pairs, 
//    while permitting multiple entries with the same key.
// 2. It store key value pair in sorted order on the basis of key (assending/decending).
// 3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
// 4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
// 5. We dont have at() and [] functions to get element like we had in std::map.

#include<iostream>
#include<map>
using namespace std;

int main()
{
    multimap<char,int,greater<>> multimap;
    multimap.insert(pair<char,int>('a',1));
    multimap.insert(make_pair('a',2));
    multimap.insert(make_pair('a',3));
    multimap.insert(make_pair('b',1));
    multimap.insert(make_pair('b',2));

    for(auto &el1: multimap)
    {
        cout<<el1.first<<" "<<el1.second<<endl;
    }
    cout<<endl;

    auto range=multimap.equal_range('a');
    for(auto it=range.first;it!=range.second;++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}