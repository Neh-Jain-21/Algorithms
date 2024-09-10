// 1. std::map is associative container that store elements in key value combination
//    where key should be unique, otherwise it overrides the previous value.
// 2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
// 3. It store key value pair in sorted order on the basis of key (assending/decending).
// 4. std::map is generally used in Dictionay type problems.

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main()
{
    map<string,int,greater<>> Map;
    Map["Papa"]=7111974;
    Map["Mummy"]=18091977;
    Map.insert(make_pair("Me",21012001));

    for(auto &el1: Map)
    {
        cout<<el1.first<<" "<<el1.second<<endl;
    }
    Map["Papa"]=0;
    cout<<Map["Papa"]<<endl;
    cout<<endl;
    map<string,vector<int>,greater<>> Map1;
    Map1["Papa"].push_back(7111974);
    Map1["Mummy"].push_back(21012001);
    Map1["Mummy"].push_back(18091977);

    for(auto &el1: Map1)
    {
        cout<<el1.first<<endl;
        for(auto &el2: el1.second)
        {
            cout<<el2<<" ";
        }
        cout<<endl;
    }

}