// 0. Fills the range [first, last) with sequentially increasing values,
//    starting with value and repetitively evaluating ++value.

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    vector<int> vec(5);
    iota(vec.begin(),vec.end(),0);
    for(auto& elm: vec)
    {
        cout<<elm<<" ";
    }
    cout<<endl<<endl;

    int arr[5];
    iota(begin(arr),end(arr),6);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
}