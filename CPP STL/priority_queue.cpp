// . std::priority_queue is a container adaptor that provides constant time lookup of the 
//    largest OR smallest element.
// 1. By default std::vector is the container used inside.
// 2. Cost of insertion and extraction is logarithmic.
// 3. std::priority_queue is implemented using std::make_heap, std::push_heap, std::pop_heap functions.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T> void print_queue(T& q)
{
    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main()
{
    priority_queue<int> q;
    for(int elm: {1,8,5,6,3,4,0,9,7,2})
    {
        q.push(elm);

    }
    print_queue(q);

    priority_queue<int, vector<int>, greater<int>> q2;
    for(int elm: {1,8,5,6,3,4,0,9,7,2})
    {
        q2.push(elm);
    }
    print_queue(q2);

    //user defined
    auto cmp=[](int left, int right)
    {
        return (left)<(right);
    };
    priority_queue<int, vector<int>, decltype(cmp)>q3(cmp);
    for(int elm: {1,8,5,6,3,4,0,9,7,2})
    {
        q3.push(elm);
    }
    print_queue(q3);
}