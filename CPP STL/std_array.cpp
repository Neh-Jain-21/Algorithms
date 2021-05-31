// 1. std::array is a container that encapsulates fixed size arrays.
// 2. array size is needed at compile time.
// 3. Assign by value is actually by value.
// 4. Access Elements:
//    a. at()
//    b. []
//    c. front()
//    d. back()
//    e. data() // gives access to the underlying array

#include<iostream>
#include<array>
using namespace std;

int main()
{
    //Declare
    array<int,5> arr;
    arr.fill(10);

    //Initialization
    array<int,5> arr1={1,2,3,4,5};
    cout<<arr1.size();
    array<int,5> arr2 {1,2,3,4,5};

    //Assign using initializer list
    array<int,5> arr3;
    arr3={1,2,3,4,5};

    return 0;
}