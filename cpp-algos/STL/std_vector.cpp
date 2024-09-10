// NOTES:
// 1. std::vector is a sequence container and also known as Dynamic Array or Array List.
// 2. Its size can grow and shrink dynamically, and no need to provide size at compile time.

// ELEMENT ACCESS
// at(), [], front(), back(), data()

// MODIFIERS:
// insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //Declarations
    vector<int> arr1;
    vector<int> arr2 (5,10);
    vector<int> arr3 = {1,2,3,4,5};
    vector<int> arr4 {1,2,3,4,5};

    cout<<arr3.at(2)<<endl;
    cout<<arr3.size()<<endl;
}