#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size,data,sin,dou1,dou2;
    cin>>size;
    vector<int> arr;
    for(int i=0; i<size; i++)
    {
        cin>>data;
        arr.push_back(data);
    }
    cin>>sin;
    cin>>dou1>>dou2;
    arr.erase(arr.begin()+sin-1);
    arr.erase(arr.begin()+dou1-1,arr.begin()+dou2-1);
    cout<<arr.size()<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
