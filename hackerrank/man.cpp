#include<iostream>
#include<vector>
#include<string>
#include<set>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int size;
    string data;
    cin>>size;
    int count[size];
    vector<string> customers;
    vector<string> temp;
    vector<string> result;
    set<string> s1;
    customers.reserve(size);
    temp.reserve(size);
    for (int i = 0; i < size; i++)
    {
        cin>>data;
        customers.push_back(data);
        s1.insert(data);
    }
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<customers[i];
    // }
    // cout<<endl;
    for(string i: s1)
    {
        temp.push_back(i);
    }

    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout<<temp[i];
    // }

    for (int i = 0; i < size; i++)
    {
        count[i]=0;
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < temp.size(); j++)
        {
            if (customers[i]==temp[j])
            {
                count[j]++;
            }      
        }
    }
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout<<count[i]<<endl;
    // }
    result.reserve(size);
    for (int i = 0; i < temp.size(); i++)
    {
        if (count[i]>=size*5/100)
        {
            result.push_back(temp[i]);
        }        
    }
    cout<<endl;
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<result[i]<<endl;
    }
    
}