// 0. partial_sort rearranges elements such that the range [first, middle) contains the sorted elements.
// 1. The order of equal elements is not guaranted to be preserved.
// 2. The order of remaining elements is unspecified.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec {8,7,6,5,4,3,2,1};
    partial_sort(vec.begin()+1,vec.begin()+5,vec.end()-1);
    for(auto& elm: vec)
    {
        cout<<elm<<" ";
    }
    return 0;
}