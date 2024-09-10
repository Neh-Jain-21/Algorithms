// 1. std::multiset is an Associative Container that contains a sorted set of duplicate objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in multiset then we will have to provide 
//    compare function so that multiset can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// multiset is similar to set except it can have multiple elements with same value.

#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

class person
{
public:
    float age;
    string name;
    bool operator < (const person& rhs) const { return age < rhs.age;}
    bool operator > (const person& rhs) const { return age > rhs.age;}
};

int main()
{
    multiset<int> MultiSet1={1,2,3,5,4,1,2,3};
    for(const auto& e: MultiSet1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    multiset<person, less<>> MultiSet2={{30,"Rupesh"},{25,"Hitz"},{22,"john"}};
    for(const auto& e: MultiSet2)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }
    cout<<endl;
    multiset<person, less<>> MultiSet3={{30,"Rupesh"},{25,"Hitz"},{22,"john"}};
    for(const auto& e: MultiSet3)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }
    return 0;
}