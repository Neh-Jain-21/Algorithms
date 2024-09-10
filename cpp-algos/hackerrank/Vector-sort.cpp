#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int size,data;
    cin>>size;
    vector<int> arr;
    arr.reserve(size);
    for (int i = 0; i < size; i++)
    {
        cin>>data;
        arr.push_back(data);
    }
    sort(arr.begin(),arr.end());
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
