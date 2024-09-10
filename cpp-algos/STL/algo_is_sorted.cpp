// 0. Checks if the elements in range [first, last) are sorted in non-descending order.

// TYPES:
// 1. Can check integral data types
// 2. Can check user defined data types
// 3. Can check using a function object
// // 4. Can check using lambda expression

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec {5,4,3,2,1};
    sort(vec.begin(),vec.end());
    for(auto& elm: vec)
    {
        cout<<elm<<" ";
    }
    cout<<endl;
    if (is_sorted(vec.begin(),vec.end()))
    {
        cout<<"Sorted";
    }
    else
    {
        cout<<"Not Sorted";
    }
    
    cout<<endl;

    vec={1,2,3,4,5};
    sort(vec.begin(),vec.end(),greater<int>());
    for(auto& elm: vec)
    {
        cout<<elm<<" ";
    }
    cout<<endl;
    if (is_sorted(vec.begin(),vec.end(),greater<int>()))
    {
        cout<<"Sorted";
    }
    else
    {
        cout<<"Not Sorted";
    }
    
    cout<<endl;

    return 0;
}

// We an use all Types as previously shown in algo_sort.cpp