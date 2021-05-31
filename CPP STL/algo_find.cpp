// 0. STL algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting, manipulating) 
// 1. Algorithms are applied to range of elements.

#include<iostream>
#include<algorithm>
#include<vector>    
using namespace std;

int main()
{
    vector<int> Vec{1,2,3,4,5,6};
    vector<int>::iterator it1 = find(Vec.begin(), Vec.end(), 9);
    auto it2 = find(Vec.begin(), Vec.end(), 5);
    if(it1==Vec.end())
    {
        cout<<"9 Not Found"<<endl;
    }
    else
    {
        cout<<"9 Found"<<endl;
    }
    
    if(it2==Vec.end())
    {
        cout<<"5 Not Found"<<endl;
    }
    else
    {
        cout<<"5 Found"<<endl;
    }

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i]=i;
    }

    auto it3= find(begin(arr), end(arr), 4);
    if(it3==end(arr))
    {
        cout<<"4 Not Found"<<endl;
    }
    else
    {
        cout<<"4 Found"<<endl;
    }

    return 0;
}