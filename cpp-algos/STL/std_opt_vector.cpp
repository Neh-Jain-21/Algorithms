#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    vec.reserve(30);
    for (int i = 0; i < 30; i++)
    {
        vec.push_back(10);
        cout<<vec[i]<<"  Size:"<<vec.size()<<" Capacity:"<<vec.capacity()<<endl;
    }
    return 0;
}