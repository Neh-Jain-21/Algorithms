// 0. Find how many elements are sorted in given range [First, last).

// TYPES:
// 1. Can check integral data types
// 2. Can check user defined data types
// 3. Can check using a function object
// // 4. Can check using lambda expression

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec {4,3,2,1,6,7,8};
    auto it1 = is_sorted_until(vec.begin(), vec.end());
    auto diff=distance(vec.begin(), it1);
    cout<<diff<<endl;
    it1 = is_sorted_until(vec.begin(), vec.end(), greater<int>());
    diff=distance(vec.begin(), it1);
    cout<<diff<<endl;
    return 0;
}