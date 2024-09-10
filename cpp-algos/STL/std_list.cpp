// 1. This is double linked list what we know from C prgramming language.
// 2. List is sequence container that allow non-contiguous memory allocation.
// 3. List is faster compared to other sequence containers (vector, forward_list, deque) in terms of 
//    insertion, removal and moving elements in any position provided we have the iterator of the position. 
// 4. We should use this class instead of traditional double linked list because
//    a. Well tested
//    b. Bunch of available function
// 5. Few Available Operations
//    operator =, assign, front, back, empty, size, max_size, clear, insert, emplace, push_back, pop_back, push_front
//    pop_front, reverse, sort, merge, splice, unique, remove, remove_if, resize.

#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> list1 = {1,2,3,4};
    list<int> list2 = {4,3,2,1};
    cout<<"List1 Size "<<distance(list1.begin(),list1.end())<<endl;
    cout<<"List2 Size "<<distance(list2.begin(),list2.end())<<endl;

    //same as forward_list

    for(auto& elm: list1)
    {
        cout<<elm<<endl;
    }
}