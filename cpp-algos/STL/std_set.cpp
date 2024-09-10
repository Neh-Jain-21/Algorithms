// NOTES:
// 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key.
// 2. It is usually implemented using Red-Black Tree.
// 3. Insertion, Removal, Search have logarithmic complexity.
// 4. If we want to store user defined data type in set then we will have to provide 
//    compare function so that set can store them in sorted order.
// 5. We can pass the order of sorting while constructing set object.

// BOTTOM LINE:
// It store unique elements and they are stored in sorted order (A/D)

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
    set<int> Set1={1,2,3,5,4,1,2,3};
    for(const auto& e: Set1)
    {
        cout<<e<<endl;
    }
    cout<<endl;
    set<person, less<>> Set2={{30,"Rupesh"},{25,"Hitz"},{22,"john"}};
    for(const auto& e: Set2)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }
    cout<<endl;
    set<person, less<>> Set3={{30,"Rupesh"},{25,"Hitz"},{22,"john"}};
    for(const auto& e: Set3)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }
    return 0;
}