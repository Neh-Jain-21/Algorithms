#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int size,data,query,Data1,first,last,middle;
    vector<int> arr;
    vector<int> num;
    cin>>size;
    arr.reserve(size);
    for (int i = 0; i < size; i++)
    {
        cin>>data;
        arr.push_back(data);
    }
    cin>>query;
    num.reserve(query);
    for (int i = 0; i < query; i++)
    {
        cin>>data;
        num.push_back(data);
    }
    for (int i = 0; i < num.size(); i++)
    {
        int j=0;
        Data1=num[i];
        while(arr[j]!=Data1)
        {
            j++;
        }
        if(j<=size)
        {
            cout<<"Yes "<<j+1<<endl;
        }
        else
        {
            int k=0;
            while (arr[k]<=Data1)
            {
                k++;
            }
            if (k<=size)
            {
                cout<<"No "<<k+1<<endl;                
            }            
        }
    }
    
    return 0;
}