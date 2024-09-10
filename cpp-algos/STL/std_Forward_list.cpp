// 1. This is single linked list what we know from C programming language.
// 2. Why forward_list why not single_list ?
// 3. We should use this class instead of traditional single linked list because
//    a. Well tested
//    b. Bunch of available function
// 4. Few Available Operations
//    operator =, assign, front, empty, max_size, clear, insert_after, emplace_after, reverse, sort, merge
//    splice_after, unique, remove, remove_if, resize

#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> list1 = {1,2,3,4};
    forward_list<int> list2 = {4,3,2,1};
    cout<<"List1 Size "<<distance(list1.begin(),list1.end())<<endl;
    cout<<"List2 Size "<<distance(list2.begin(),list2.end())<<endl;
    
    //tranfer one list to another
    //list1=list2;

    //Assign 0 to all
    //list1.assign(5,0);

    //clear all value
    //list1.clear();

    //insert after
    //list1.insert_after(list1.begin(),10);

    //list1.reverse();

    //list1.sort();

    //list1.merge(list2);

    //list1.splice_after(list2.begin(),list2);

    //list1.unique();

    //list1.remove(2);

    // list1.remove_if([] (int n) {
    //     return n>2;
    // });

    //list1.resize(2);

    for(auto& elm: list1)
    {
        cout<<elm<<endl;
    }
    return 0;
}