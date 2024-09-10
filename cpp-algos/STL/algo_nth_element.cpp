#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec {5,6,4,3,2,6,7,9,3};
    
    nth_element(vec.begin(), vec.begin()+vec.size()/2,vec.end());
    cout<<"Median is "<<vec[vec.size()/2]<<endl;

    nth_element(vec.begin(), vec.begin()+1,vec.end(),greater<int>());
    cout<<"Second Largest Element "<<vec[1]<<endl;
}