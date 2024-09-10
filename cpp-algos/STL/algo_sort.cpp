#include<iostream>
#include<vector>
#include<algorithm>
#include<execution>
using namespace std;

//1. Sorting Integral Datatypes
int main()
{
    vector<int> vec = {9,8,7,6,5,4,3,2,1};
    //sort(std::execution::par, vec.begin(), vec.end());
    sort(vec.begin(), vec.end());
    for(auto& elm: vec)
    {
        cout<<elm<<" ";
    }
    cout<<endl;
    int arr[]={5,4,3,2,1};
    sort(begin(arr),end(arr));
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

//2. Sorting User Defined Data Type
// class Point
// {
// public:
//     int x,y;
//     Point(int x=0,int y=0):x{x}, y{y} {}
//     bool operator < (const Point& p1)
//     {
//         return (x+y)<(p1.x+p1.y);
//     }
// };

// int main()
// {
//     vector<Point> vec {{1,2}, {3,1}, {0,1}};
//     sort(vec.begin(), vec.end());
//     for(auto& elm: vec)
//     {
//         cout<<elm.x<<" "<<elm.y<<endl;
//     }
//     return 0;
// }

//3. Sort using Functon Object
// struct
// {
//     bool operator()(int a, int b) const
//     {
//         return a < b;
//     }
// } custom;

// int main()
// {
//     vector<int> vec {5,4,3,2,1};
//     sort(vec.begin(), vec.end(), greater<int>());
//     for(auto& elm: vec)
//     {
//         cout<<elm<<" ";
//     }
//     cout<<endl<<endl;
//     sort(vec.begin(), vec.end(), custom);
//     for(auto& elm: vec)
//     {
//         cout<<elm<<" ";
//     }
//     return 0;
// }

//4. sort using lamda function
// int main()
// {
//     vector<int> vec {5,4,3,2,1};
//     sort(vec.begin(), vec.end(), [](int a,int b) {return a<b; });
//     for(auto& elm: vec)
//     {
//         cout<<elm<<" ";
//     }
//     return 0;
// }