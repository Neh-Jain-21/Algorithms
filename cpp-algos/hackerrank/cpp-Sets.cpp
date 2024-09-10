#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() 
{
    int count;
    set<int> s;
    cin>>count;
    int x[count],y[count];
    for (int i = 0; i < count; i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int i = 0; i < count; i++)
    {
        if (x[i]==1)
        {
            s.insert(y[i]);
        }
        if (x[i]==2)
        {
            s.erase(y[i]);
        }
        if (x[i]==3)
        {
            auto itr=s.find(y[i]);
            if(itr==s.end())
            {
                cout<<"No"<<endl;
            }
            else
            {
                cout<<"Yes"<<endl;
            }
        }
    }
    
    return 0;
}



