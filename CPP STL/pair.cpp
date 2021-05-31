// 0. std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
// 1. map, multimap, unorder_map, unorder_multimap can use pair to insert data into their structures.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(pair<int,int>& obj)
{
    cout<<obj.first<<" "<<obj.second<<endl;
}

int main()
{
    {
        pair<int,int> obj(10,20);
        print(obj);
    }
    {
        pair<int,int> obj=make_pair(30,40);
        print(obj);
    }
    {
        vector<pair<string,int>> list;
        list.push_back(make_pair("Neh",39));
        list.push_back(pair<string,int>("Manthan",36));
        list.push_back(pair<string,int>("Meet",38));
        for(auto& elm: list)
        {
            cout<<elm.first<<" "<<elm.second<<endl;
        }
    }
    return 0;
}